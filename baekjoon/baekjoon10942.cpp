#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
int num[2001];
int dp[2001][2001];

bool make_dp(int S, int E) {


	int &ret = dp[S][E];

	if (S == E) {
		ret = 1;
		return ret;
	}
	else if (E - S == 1 && E - S >= 0) {

		if (num[S] == num[E])
			ret = 1;
		else
			ret = 0;

		return ret;
	}
	else if (E - S > 1 && E - S >= 0 && S+1 < N+1 && E-1 >= 0) {

		if (dp[S + 1][E - 1] == -1) {
			ret = make_dp(S + 1, E - 1) & (num[S] == num[E] ? 1 : 0);
			return ret;
		}
		else {
			ret = dp[S + 1][E - 1] & (num[S] == num[E] ? 1 : 0);
			return ret;
		}
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= 2000; i++)
		memset(dp[i], -1, sizeof(int)*2001);

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &num[i]);
	}
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int S, E;
		scanf("%d %d", &S, &E);
		
		printf("%d\n", make_dp(S, E));
	}



    return 0;
}

