
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int cost[1001][3];
	int dp[1001][3] = { 0, };
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}

	int ans = 99999999;

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			if (i == j) {
				dp[0][j] = cost[0][j];
			}
			else
				dp[0][j] = 99999999;
		}

		for (int j = 1; j < N; j++) {

			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
			dp[j][1] = min(dp[j - 1][2], dp[j - 1][0]) + cost[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + cost[j][2];

		}

		for (int j = 0; j < 3; j++) {
			if (i == j) {
				continue;
			}
			else
				ans = min(ans, dp[N-1][j]);
		}

	}


	printf("%d\n", ans);
	

    return 0;
}

