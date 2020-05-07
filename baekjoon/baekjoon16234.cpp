#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int N;
int population[50][50];
int L, R;


int main()
{
	int ans = 0;

	scanf("%d %d %d", &N,&L,&R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &population[i][j]);
		}
	}

	bool move = true;

	int mX[4] = {0,1,0,-1};
	int mY[4] = {1,0,-1,0};

	while (move) {

		move = false;
		bool visited[50][50] = { 0, };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j])
					continue;
				queue<pair<int,int>> q;
				
				q.push({ i,j });
				visited[i][j] = 1;
				vector<pair<int, int>> update;
				int sum_pop = 0;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					sum_pop += population[x][y];
					update.push_back({ x,y });
					q.pop();

					for (int k = 0; k < 4; k++) {
						int mx = x + mX[k];
						int my = y + mY[k];
						int diff = abs(population[x][y] - population[mx][my]);

						if (mx >= 0 && mx <= N - 1 && my >= 0 && my <= N - 1) {
							if (!visited[mx][my] && diff >= L && diff <= R) {
								q.push({ mx,my });
								visited[mx][my] = 1;
								move = true;
							}
						}
					}
				}

				int div = sum_pop / update.size();

				for (int k = 0; k < update.size(); k++) {
					
					population[update[k].first][update[k].second] = div;
				}


			}
		}

		if (move) {
			ans++;
		}
	}

	printf("%d\n", ans);

    return 0;
}

