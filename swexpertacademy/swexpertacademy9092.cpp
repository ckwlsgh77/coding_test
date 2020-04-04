#include <stdio.h>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

int dp[501][501]; // 현재위치, 남은 점프수
int n, k;
pair<int,int> point[501];

int dist(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int cal(int now, int left_jump) {
	if (now == n) return 0;

	int &ret = dp[now][left_jump];

	if (ret != -1)
		return ret;
	
	ret = 999999999;

	for (int i = 0; i <= left_jump; i++) {
		int next = now + 1 + i;
		if (next > n) 
			break;
		int dist_next = dist(point[now], point[next]);
		ret = min(ret, dist_next + cal(next, left_jump - i));
	}

	return ret;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	for (int turn = 1; turn <= TC; turn++) {
		scanf("%d %d", &n, &k);
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &point[i].first, &point[i].second);
		}

		int ans = cal(1, k);

		printf("#%d %d\n", turn, ans);

	}
    return 0;
}

