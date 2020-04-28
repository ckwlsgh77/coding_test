
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<pair<int,int>> house;
int n;
int **cache;

int tsp(int cur, int visited) {

	if (visited == (1 << n + 2) - 3) return abs(house[cur].first - house[1].first) + abs(house[cur].second - house[1].second);
	
	int &ret = cache[cur][visited];
	if (ret != 0) return ret;
	ret = 999999;
	for (int next = 2; next < n + 2; next++) {
		if (visited & (1 << next))continue;

		ret = min(ret, tsp(next, visited | (1 << next)) + abs(house[cur].first - house[next].first) + abs(house[cur].second - house[next].second));

	}
	return ret;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		
		int ans = 0;

		scanf("%d", &n);

		cache = (int**)malloc(sizeof(int*)*(n+2));
		for (int i = 0; i < n + 2; i++) {
			cache[i] = (int*)malloc(sizeof(int)*(1 << n + 2));
			memset(cache[i], 0, sizeof(int)*(1 << n + 2));
		}

		
		for (int i = 0; i < n + 2; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			house.push_back({ x,y });
		}

		ans = tsp(0, 1);

		for (int i = 0; i < n + 2; i++) {
			free(cache[i]);
		}
		free(cache);
		house.clear();

		printf("#%d %d\n", t+1, ans);
	}

    return 0;
}

