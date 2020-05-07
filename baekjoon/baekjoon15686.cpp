#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;

vector<pair<int, int>> chicken;
vector<bool> check(13,0);
vector<pair<int, int>> house;
vector<int> house_to_chicken;
int ans = 99999;
int M, N;

void dfs(int cur, int count) {
	if (cur > chicken.size()) {
		return;
	}

	if (count == M) {
		int sum_distance = 0;
		for (int i = 0; i < house.size(); i++) {
			int house_distance = 9999;
			for (int j = 0; j < chicken.size(); j++) {

				if (check[j] == 1) {

					int tmp = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);

					if (house_distance > tmp)
						house_distance = tmp;
				}

			}
			sum_distance += house_distance;
		}

		ans = min(ans, sum_distance);
	}

	check[cur] = 1;
	dfs(cur + 1, count + 1);

	check[cur] = 0;
	dfs(cur + 1, count);

}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1) {
				house.push_back({ i,j });

			}
			else if (tmp == 2) {
				chicken.push_back({ i,j });

			}
			else if (tmp == 0) {
				continue;
			}
		}

	

	dfs(0, 0);
	
	printf("%d\n", ans);

    return 0;
}

