#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
	int TC;
	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++) {
		int N;
		scanf("%d", &N);

		bool *check = (bool*)malloc(sizeof(bool)*(N+1));
		memset(check, 0, sizeof(bool)*(N+1));
		int tmp;
		int ans = 0;

		for (int i = 1; i <= N; i++) {
			scanf("%d", &tmp);
			if (check[tmp - 1] == 1) {
				check[tmp] = 1;
			}
			else {
				ans++;
				check[tmp] = 1;
			}
		}	

		printf("#%d %d\n", t, ans);
		
		free(check);

	}
    return 0;
}

