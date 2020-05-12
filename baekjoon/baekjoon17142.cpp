#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map(50, vector<int>(50, 0));
vector<pair<int, int>> two_position;
int ans = 9999;
int mX[4] = { 0, 1 ,0, -1 };
int mY[4] = { 1, 0 ,-1, 0 };
int zero_count = 0;


int bfs(int bit) {
	int sec = 0;

	queue<pair<int,int>> q;

	for (int i = 0; i < two_position.size(); i++) {
		if (bit & (1 << i)) {
			q.push({ two_position[i].first ,two_position[i].second });
			map[two_position[i].first][two_position[i].second] = 3;
		}
	}
	
	
	bool check = true;

	while (check) {
		check = false;
		int tmp_zero = zero_count;
		vector<pair<int, int>> candidate;

		if (sec > ans)
			return 9999;


		while (!q.empty()) {

			int tmp_x = q.front().first;
			int tmp_y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {

				int mx = tmp_x + mX[i];
				int my = tmp_y + mY[i];

				if (mx >= 0 && mx < N && my >= 0 && my < N) {
					if (map[mx][my] == 1 || map[mx][my] == 3) {
						continue;
					}
					else {
						if (map[mx][my] == 0)
							zero_count--;
						candidate.push_back({ mx,my });						
						check = true;						
						map[mx][my] = 3;
					}
				}
			}
		}

		
		

		for (int i = 0; i < candidate.size(); i++) {	
			q.push({ candidate[i].first,candidate[i].second });
			
		}
		
		if (tmp_zero)
			sec++;

	}

	

	return sec;
}


bool yes() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0)
				return false;
		}
	}
	return true;
}


void cal(int count, int bit, int depth) {

	if (depth > two_position.size())
		return;

	if (count == M) {
		bool ret_yes = true;
		vector<vector<int>> tmp_map = map;
		int tmp_zero = zero_count;
		int tmp = bfs(bit);
		if (zero_count > 0)
			ret_yes = false;
		zero_count = tmp_zero;
		map = tmp_map;

		if (ret_yes && tmp < ans) {
			ans = tmp;
		}

		return;
	}



	cal(count + 1, bit | (1 << depth), depth + 1);
	cal(count, bit, depth + 1);



}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				two_position.push_back({ i,j });
			}
			else if (map[i][j] == 0) {
				zero_count++;
			}
		}
	}
	cal(0, 0, 0);
	if (ans == 9999)
		ans = -1;

	printf("%d\n", ans);

	return 0;
}

