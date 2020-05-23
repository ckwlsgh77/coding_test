#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;


int d(pair<int,int> x, pair<int,int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

int main()
{

	int test;
	scanf("%d", &test);
	
	for (int t = 1; t <= test; t++) {
		int N;
		scanf("%d", &N);

		vector<pair<int, int>> pos(N+2);
		vector<vector<int>> dist(N + 2, vector<int>(N + 2, 0));
		for (int i = 0; i < N + 2; i++) {
			int x, y;
			scanf("%d %d",&x, &y);

			pos[i].first = x;
			pos[i].second = y;

		}

		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				dist[i][j] = d(pos[i], pos[j]);
			}
		}

		queue<int> q;
		q.push(0);
		
		bool visited[101] = { 0, };
		visited[0] = 1;
		bool ans = false;

		while (!q.empty()) {
			int tmp = q.front();
			q.pop();

			for (int i = 0; i < N + 2; i++) {

				if (visited[i] != 1) {

					int need_beer = dist[tmp][i] / 50;
					if (dist[tmp][i] % 50 != 0)
						need_beer++;

					if (need_beer <= 20) {

						if (i == N + 1) {
							ans = true;
							break;
						}
						q.push(i);
						visited[i] = 1;

					}
				}
			}
			if (ans == true)
				break;
		}

		if (ans)
			printf("happy\n");
		else
			printf("sad\n");


	}
    return 0;
}

