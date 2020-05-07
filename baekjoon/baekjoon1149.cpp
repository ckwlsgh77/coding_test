#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int cost[1000][3];
int dp[1000][3];
int N;



int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	int ans = 999999999;

	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];
	for (int i = 1; i < N; i++) {

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];

		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
	}

	for (int i = 0; i < 3; i++) {
		ans = min(ans, dp[N - 1][i]);
	}
	printf("%d\n", ans);

    return 0;
}

