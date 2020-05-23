#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
bool visited[110001] = { 0, };
int dist[110001] = { 0, };
int N, K, M;
int ans = -1;

int main()
{
	scanf("%d %d %d", &N, &K, &M);

	v.resize(N + M + 1);

	int x;
	for (int i = N + 1; i < N + M + 1; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &x);

			v[x].push_back(i);
			v[i].push_back(x);
		}
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	dist[1] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == N) {
			break;
		}
		else {
			for (int i = 0; i < v[cur].size(); i++) {
				int tmp = v[cur][i];

				if (visited[tmp] == 0) {
					visited[tmp] = 1;
					q.push(tmp);
					dist[tmp] = dist[cur] + 1;
				}
			}

		}
	}
	if (dist[N] == 0)
		printf("-1");
	else
		printf("%d\n", dist[N] / 2 + 1);
}