#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
int ans = -1;
bool visited[1000001] = { 0, };
int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	
	queue<pair<int,int>> q;
	q.push({ S,0 });
	visited[S] = 1;

	while (!q.empty()) {

		int cur = q.front().first;

		if (cur == G) {
			ans = q.front().second;
			break;
		}

		int depth = q.front().second;
		q.pop();

		if (cur + U <= F) {
			if (visited[cur + U] == 0) {
				q.push({ cur + U ,depth + 1 });
				visited[cur + U] = 1;
			}
		}
		if (cur - D >= 1) {
			if (visited[cur - D] == 0) {
				q.push({ cur - D,depth + 1 });
				visited[cur - D] = 1;
			}
		}

	}

	if(ans >= 0)
		printf("%d\n", ans);
	else
		printf("use the stairs\n");

    return 0;
}

