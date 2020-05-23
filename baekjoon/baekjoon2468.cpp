#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N;
int map[100][100];
int ans = 1;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			scanf("%d", &tmp);
			map[i][j] = tmp;
		}
	}
	int water = 0;
	int mX[4] = { 0,0,1,-1 };
	int mY[4] = { 1,-1,0,0 };

	while (water <= 100) {
		
		bool visited[100][100] = { 0, };
		int tmp_ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (map[i][j] > water && visited[i][j] == 0) {
					visited[i][j] = 1;
					tmp_ans++;
					queue<pair<int, int>> q;
					q.push({ i,j });

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;

						q.pop();
						for (int k = 0; k < 4; k++) {
							int mx = x + mX[k];
							int my = y + mY[k];

							if (mx >= 0 && mx < N && my >= 0 && my < N) {

								if (map[mx][my] > water && visited[mx][my] == 0) {
									visited[mx][my] = 1;
									q.push({ mx,my });
								}
							}

						}

					}
				}

			}
		}

		if (ans < tmp_ans) {
			ans = tmp_ans;
		}
		
		water++;
	}
	printf("%d\n", ans);
    return 0;
}

