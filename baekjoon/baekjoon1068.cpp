#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[50];
bool check[50] = { 0, };

int ans = 0;
void bfs(int start) {
	check[start] = true;

	queue<int> q;

	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		int child_cnt = 0;
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (!check[next]) {
				child_cnt++;
				check[next] = true;
				q.push(next);
			}
		}
		if (child_cnt == 0) {
			ans++;
		}

	}


}

int main(void) {
	int n;
	scanf("%d", &n);
	int num;
	int root;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num == -1) {
			root = i;
		}
		else {
			v[num].push_back(i);
		}
	}

	int rem;
	scanf("%d", &rem);
	check[rem] = true;

	if (rem != root) {
		bfs(root);
	}

	printf("%d\n", ans);
}