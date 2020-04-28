#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int N, M;
bool theend = false;

int rec(int start, int dest, vector<bool> visited, vector<vector<pair<int, int>>> V) {
	int ans = 0;
	visited[start] = 1;
	
	if (start == dest) {
		theend = true;
		return ans;
	}

	for (int i = 0; V[start].size(); i++) {
		int next = V[start][i].first;

		if (visited[next] == 1)
			continue;
		int tmp = ans;

		ans = ans + V[start][i].second + rec(next, dest, visited, V);
		
		visited[next] = 0;
		if (theend) {
			break;
		}
		ans = tmp;
		

	}
	if (!theend) {
		return 0;
	}

	visited[start] = 0;
	return ans;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d %d", &N, &M);

		vector<vector<pair<int,int>>> V(N+1, vector<pair<int,int>>());
		bool first = false;

		for (int i = 0; i < M; i++) {
			char c[2];
			int a, b, w;
			int ans = -1;
			
			scanf("%s", c);
			if (c[0] == '!') {

				scanf("%d %d %d", &a, &b, &w);
				V[b].push_back({ a,w });
				V[a].push_back({ b,-w });

			}
			else if (c[0] == '?') {
				scanf("%d %d", &a, &b);

				vector<bool> visited(N+1, 0);

				if (!first) {
					printf("#%d", t);
					first = true;
				}

				ans = rec(b, a,visited, V);

				if (theend == false)
					printf(" UNKNOWN\n");
				else {
					printf(" %d\n", ans);
					V[b].push_back({ a,ans });
					V[a].push_back({ b,-ans });
				}

				theend = false;
			}
		}

	}
    return 0;
}

