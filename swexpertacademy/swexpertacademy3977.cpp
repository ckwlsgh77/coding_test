#include <stdio.h>
#include <math.h>


int main()
{
	int TC;
	scanf("%d", &TC);
	bool prime[1000000] = { 0, };

	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == 0) {
			for (int j = i * 2; j <= 1000000; j += i) {
				prime[j] = 1;
			}
		}
	}



	for (int t = 1; t <= TC; t++) {
		int L, R, ans = 0;
		scanf("%d %d", &L, &R);
		bool search = 0;

		while (L <= R) {
			if (L == 2) {
				ans++;
				L++;
				continue;
			}
			
			if (prime[L] == 0) {
				
				if ((L%4) == 1) {
					ans++;
					search = 1;
				}
			}
			

			if (!search) {
				L++;
			}
			else {
				L += 4;
			}

		}


		printf("#%d %d\n", t, ans);
	}
    return 0;
}

