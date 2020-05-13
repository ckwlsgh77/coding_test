#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> horse_pos;
vector<int> horse_dir;
vector<vector<int>> map(12, vector<int>(12, 0));
vector<int> chesschain[12][12];

int N, K;
int mX[5] = { 0,0,0,-1,1 };
int mY[5] = { 0,1,-1,0,0 };

int mov(int idx) {

	int d = horse_dir[idx];
	int mx = horse_pos[idx].first + mX[d];
	int my = horse_pos[idx].second + mY[d];

	if (mx >= 0 && mx < N&& my >= 0 && my < N) {
		if (map[mx][my] == 2) {
			switch (horse_dir[idx]) {
				case 1:
					horse_dir[idx] = 2;
					break;
				case 2:
					horse_dir[idx] = 1;
					break;
				case 3:
					horse_dir[idx] = 4;
					break;
				case 4:
					horse_dir[idx] = 3;
					break;
			}
			d = horse_dir[idx];
			mx = horse_pos[idx].first + mX[d];
			my = horse_pos[idx].second + mY[d];

			if (!(mx >= 0 && mx < N&& my >= 0 && my < N))
				return 0;
			if (map[mx][my] == 2)
				return 0;
		}
	}
	else {
		switch (horse_dir[idx]) {
		case 1:
			horse_dir[idx] = 2;
			break;
		case 2:
			horse_dir[idx] = 1;
			break;
		case 3:
			horse_dir[idx] = 4;
			break;
		case 4:
			horse_dir[idx] = 3;
			break;
		}
		d = horse_dir[idx];
		mx = horse_pos[idx].first + mX[d];
		my = horse_pos[idx].second + mY[d];

		if (!(mx >= 0 && mx < N&& my >= 0 && my < N))
			return 0;
		if (map[mx][my] == 2)
			return 0;
	}

	vector<int> &v = chesschain[horse_pos[idx].first][horse_pos[idx].second];
	vector<int> &next = chesschain[mx][my];

	auto pos = find(v.begin(), v.end(), idx);

	if (map[mx][my] == 1) {
		reverse(pos, v.end());
	}

	for (auto it = pos; it != v.end(); it++) {
		horse_pos[*it].first = mx;
		horse_pos[*it].second = my;
		next.push_back(*it);
	}
	v.erase(pos, v.end());

	return chesschain[mx][my].size();

	
}

int simulation() {
	
	for (int i = 1; i < 1001; i++) {

		for (int j = 0; j < K; j++) {

			int stack = mov(j);

			if (stack >= 4)
				return i;
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &N, &K);
for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int x, y, d;
		scanf("%d %d %d", &x, &y, &d);
		chesschain[x-1][y-1].push_back(i);
		horse_pos.push_back({ x-1,y-1 });
		horse_dir.push_back(d);
	}
	
	int ans = simulation();

	printf("%d\n", ans);
    return 0;
}

