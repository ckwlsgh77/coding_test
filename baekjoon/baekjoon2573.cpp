#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map(300, vector<int>(300, 0));
vector<vector<int>> tmp_map(300, vector<int>(300, 0));
int N, M;


int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	bool t = true;


	int mX[4] = { 0,0,1,-1 };
	int mY[4] = { 1,-1,0,0 };
	int ans = 0;
	
	while (t) {
		int ice_count = 0;
		bool visited[300][300] = { 0, };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > 0 && visited[i][j] == 0) {
					ice_count++;
					queue<pair<int,int>> q;
					visited[i][j] = 1;
					q.push({ i,j });

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++) {
							int mx = x + mX[k];
							int my = y + mY[k];

							if (mx >= 0 && mx < N&& my >= 0 && my < M) {
								if (map[mx][my] > 0 && visited[mx][my] == 0) {
									q.push({ mx,my });
									visited[mx][my] = 1;

								}
							}
						}
					}
				}
			}
		}

		if (ice_count >= 2) {
			break;
		}
		else if (ice_count == 0) {
			ans = 0;
			break;
		}



		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > 0) {
					int sea_count = 0;
					for (int k = 0; k < 4; k++) {
						int mx = i + mX[k];
						int my = j + mY[k];

						if (mx >= 0 && mx < N&& my >= 0 && my < M) {
							if (map[mx][my] == 0) {
								sea_count++;

							}
						}
					}
					if (map[i][j] - sea_count < 0)
						tmp_map[i][j] = 0;
					else
						tmp_map[i][j] = map[i][j] - sea_count;

				}
			}
		}

		map = tmp_map;


		ans++;
	}

	printf("%d\n", ans);
    return 0;
}

