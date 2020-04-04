#include <stdio.h>
#include <malloc.h>
int main()
{
	int TC;
	scanf("%d", &TC);
	
	for (int t = 1; t <= TC; t++) {
		int N;
		
		scanf("%d", &N);

		int *day = (int*)malloc(sizeof(int)*N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &day[i]);
		}

		long long ans = 0;
		int seller_day = N - 1;
		for (int i = N - 2; i >= 0; i--) {
			if (day[seller_day] > day[i]) {
				ans = ans + day[seller_day] - day[i];
			}
			else {
				seller_day = i;
			}
		}

		printf("#%d %lld\n", t, ans);
	}
    return 0;
}

