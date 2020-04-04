#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
	int test_case;
	int T;

	scanf("%d",&T);

	for (int test_case = 1; test_case <= T; test_case++) {
		vector<int> arr[501];
		bool visited[501] = { false };
		int N, M;
		scanf("%d %d", &N, &M);

		for (int i = 0; i<M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		vector<int> stack;
		stack.push_back(1);

		visited[1] = true;
		int result = 0;

		while (!stack.empty()) {
			int cur = stack.back();
			stack.pop_back();

			for (int i = 0; i < arr[cur].size(); i++) {
				int tmp = arr[cur][i];
				if (!visited[tmp]) {
					result++;
					visited[tmp] = true;

					if (cur == 1) {
						stack.push_back(tmp);
					}
				}
			}
		}

		
		
		printf("#%d %d\n", test_case, result);

	}
	return 0;
}
