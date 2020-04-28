#include <stdio.h>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
	int R, C, T;

	scanf("%d %d %d", &R, &C, &T);

	vector<pair <int, int>> dust;
	vector<tuple <int, int, int> > update;
	vector<vector<int>> arr(R, vector<int>(C, 0));
	vector<vector<bool>> visited(R, vector<bool>(C, 0));

	int machine_1 = -1, machine_2 = -1;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int tmp;
			scanf("%d", &tmp);

			if (tmp == -1 && machine_1 == -1) {
				machine_1 = i;
			}
			else if(tmp == -1 && machine_2 == -1){
				machine_2 = i;
			}

			if (tmp > 0) {
				visited[i][j] = 1;
				dust.push_back({i, j});
			}

			arr[i][j] = tmp;
		}

	}

	int mX[4] = { -1, 0 , 1, 0 };
	int mY[4] = { 0 , -1 ,0 , 1 };

	for (int time = 0; time < T; time++) {

		for (int i = 0; i < dust.size(); i++) {

			int x = dust[i].first;
			int y = dust[i].second;

			if (visited[x][y] == 1) {
				visited[x][y] = 0;
				int cost = arr[x][y];

				int sep_cost = cost / 5;
				int count = 0;
				for (int j = 0; j < 4; j++) {
					int m_x = x + mX[j];
					int m_y = y + mY[j];

					if (m_x >= 0 && m_x < R && m_y >= 0 && m_y < C) {

						if (!((m_x == machine_1 || m_x == machine_2) && m_y == 0)) {
							if (sep_cost > 0) {
								update.push_back({ m_x,m_y,sep_cost });
								count++;
							}
						}
					}


				}
				update.push_back({ x,y,cost - sep_cost*count });
			}
		}

		dust.clear();

		for (int i = 0; i < update.size(); i++) {
			int x = get<0>(update[i]);
			int y = get<1>(update[i]);
			int cost = get<2>(update[i]);


			if (x == machine_1&& y != C - 1) {
				y++;
			}
			else if (x>0 && x <= machine_1 && y == C - 1) {
				x -= 1;
			}
			else if (x == 0 && y != 0) {
				y--;
			}
			else if (x < machine_1 && y == 0) {
				x += 1;
			}
			else if (x == machine_2 && y != C - 1) {
				y++;
			}
			else if (x<R-1 &&x >= machine_2 && y == C - 1) {
				x++;
			}
			else if (x == R - 1 && y != 0) {
				y--;
			}
			else if (x > machine_2 && y == 0) {
				x--;
			}

			if (!((x == machine_1 || x == machine_2) && y == 0)) {

				if (visited[x][y] == 0) {
					visited[x][y] = 1;
					arr[x][y] = 0;
				}

				arr[x][y] = arr[x][y] + cost;

				dust.push_back({ x,y });
			}


		}
		update.clear();

		printf("---%d---\n", time);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}

	int ans = 0;
	for (int i = 0; i < dust.size(); i++) {



		int x = dust[i].first;
		int y = dust[i].second;

		if (visited[x][y] == 1) {
			visited[x][y] = 0;

			ans += arr[x][y];
		}

	}

	printf("%d\n", ans);
    return 0;
}

