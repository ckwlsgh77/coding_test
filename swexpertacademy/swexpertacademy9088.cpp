#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int dia[10001];
int N, K;

int cal(int min_dia, int max_dia) {
	int max_ans=0;

	for (int i = min_dia; i <= max_dia; i++) {
		int count = 0;
		for (int j = i; j <= min(max_dia, i + K); j++) {
			count += dia[j];
		}

		max_ans = max(max_ans, count);
	}


	return max_ans;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	for (int i = 0; i < TC; i++) {
		
		int weight;
		int max_dia = 0;
		int min_dia = 10000;
		scanf("%d %d", &N, &K);
		memset(dia, 0, sizeof(dia));
		
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &weight);
			
			dia[weight]++;

			max_dia = max(max_dia, weight);
			min_dia = min(min_dia, weight);

		}


		int ans = 0;
		ans = cal(min_dia,max_dia);
		printf("#%d %d\n", i + 1, ans);

	}

    return 0;
}

