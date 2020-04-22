#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	int N;
	int M;
	scanf("%d %d", &N, &M);
	vector<int> m(101, 0);
	vector<int> c(101, 0);
	int sum=0;
	int ans = 99999;
	for (int i = 0; i < N; i++) {
		int first;
		scanf("%d", &first);
		m[i] = first;
	}
	for (int i = 0; i < N; i++) {
		int second;
		scanf("%d", &second);
		c[i] = second;
		sum += second;
	}
	
	vector<vector<int>> dp(101, vector<int>(sum+1, 0));
	dp[0][c[0]] = m[0];

	for (int i = 0; i < N; i++) {

		for (int j = 0; j <= sum; j++) {
			if (j - c[i] >= 0 && i-1 >=0) {

				dp[i][j] = max(dp[i][j], dp[i-1][j - c[i]] + m[i]);
			}

			if (i - 1 >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			if (dp[i][j] >= M) {
				if (ans > j) {
					ans = j;
				}
			}
		}
	}
	printf("%d\n", ans);

    return 0;
}

