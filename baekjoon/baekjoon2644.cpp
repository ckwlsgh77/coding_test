#include <stdio.h>
#include <vector>

using namespace std;

int N;
int M;
vector<int> relation[101];
bool visited[101] = { 0, };
int target_x, target_y;
int ans = -1;

void dfs(int start, int end,int depth) {

	if (start == end) {

		if (ans < depth)
			ans = depth;

		return;
	}
	

	for (int i = 0; i < relation[start].size(); i++) {
		if (visited[relation[start][i]] == 0) {
			visited[relation[start][i]] = 1;
			dfs(relation[start][i], end, depth + 1);
			visited[relation[start][i]] = 0;
		}

	}
}

int main()
{
	scanf("%d", &N);
	scanf("%d %d", &target_x, &target_y);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int tmpx;
		int tmpy;
		scanf("%d %d", &tmpx, &tmpy);

		relation[tmpx].push_back(tmpy);
		relation[tmpy].push_back(tmpx);
	}
	visited[target_x] = 1;
	dfs(target_x,target_y,0);


	printf("%d\n", ans);
    return 0;
}

