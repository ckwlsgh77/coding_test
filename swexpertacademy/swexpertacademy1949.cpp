#include <stdio.h>
#include <algorithm>

using namespace std;

int N, K;
int mountain[8][8];
int visited[8][8] = { 0, };

int mX[4] = { -1 , 1, 0, 0 };
int mY[4] = { 0, 0, -1, 1 };
int ans = 0;

void dfs(int x, int y, int depth, bool check_k) {
	
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int m_X = x + mX[i];
		int m_Y = y + mY[i];

		if (m_X >= 0 && m_X < N && m_Y >= 0 && m_Y < N && visited[m_X][m_Y] == 0) {
			if (mountain[x][y] > mountain[m_X][m_Y])
				dfs(m_X, m_Y, depth + 1, check_k);
			else {
				if (check_k == 0) {
					for (int j = 0; j <= K; j++) {
						if (mountain[x][y] > (mountain[m_X][m_Y] - j)) {
							mountain[m_X][m_Y] = mountain[m_X][m_Y] - j;
							dfs(m_X, m_Y, depth + 1, 1);
							mountain[m_X][m_Y] = mountain[m_X][m_Y] + j;
						}
					}
				}

			}
		}	
	}


	visited[x][y] = 0;

	ans = max(ans, depth);

	return;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++) {
		ans = 0;
		scanf("%d %d", &N, &K);
		int top=0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &mountain[i][j]);
				if (mountain[i][j] > top)
					top = mountain[i][j];
			}
		}

		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mountain[i][j] == top) {
					dfs(i, j, 1, 0);
				}
			}
		}

		


		printf("#%d %d\n", t, ans);
	}
    return 0;
}

