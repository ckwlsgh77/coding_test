#include <stdio.h>
#include <vector>

using namespace std;

vector<pair<int, int>> cctv;
vector<vector<int>> map(8, vector<int>(8, 0));
int N, M;;
int cctv_cnt = 0;
int ans = 9999;

void mov(int dir,int x, int y) {

	dir = dir % 4;

	switch (dir)
	{
	case 0:
		for (int i = y+1; i < M; i++) {
			if (map[x][i] == 6) break;
			if (map[x][i] == 0) map[x][i] = -1;
		}
		break;
	case 1:
		for (int i = x+1; i < N; i++) {
			if (map[i][y] == 6) break;
			if (map[i][y] == 0) map[i][y] = -1;
		}
		break;
	case 2:
		for (int i = y-1; i >= 0; i--) {
			if (map[x][i] == 6) break;
			if (map[x][i] == 0) map[x][i] = -1;
		}
		break;
	case 3:
		for (int i = x-1; i >= 0; i--) {
			if (map[i][y] == 6) break;
			if (map[i][y] == 0) map[i][y] = -1;
		}
		break;
	}

}


void dfs(int count) {

	if (count == cctv_cnt) {
		int ans_count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					ans_count++;
			}
		}

		if (ans_count < ans) {
			ans = ans_count;
		}
	
		return;
	}

	int x = cctv[count].first;
	int y = cctv[count].second;
	int cctv_num = map[x][y];

	vector<vector<int>> tmp_map = map;

	switch (cctv_num) {

	case 1:
		for (int i = 0; i < 4; i++) {
			mov(i, x, y);
			dfs(count+1);

			map = tmp_map;
		}
		
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			mov(i, x, y);
			mov(i + 2, x, y);
			dfs(count + 1);

			map = tmp_map;
		}
		
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			mov(i, x, y);
			mov(i + 3, x, y);
			dfs(count + 1);

			map = tmp_map;
		}
		
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			mov(i, x, y);
			mov(i + 2, x, y);
			mov(i + 3, x, y);
			dfs(count + 1);

			map = tmp_map;
		}
		

		break;
	case 5:
		for (int i = 0; i < 1; i++) {
			mov(i, x, y);
			mov(i + 1, x, y);
			mov(i + 2, x, y);
			mov(i + 3, x, y);
		}

		dfs(count + 1);

		break;


	}

}


int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			scanf("%d", &map[i][j]);
			
			if (map[i][j] >=1 && map[i][j] <= 5) {
				cctv.push_back({ i,j });
				cctv_cnt++;
			}
		}
	}

	dfs(0);

	printf("%d\n", ans);

    return 0;
}

