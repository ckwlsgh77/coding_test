#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{

	int TC;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		long long int n;
		long long int count = 0;
		long long int input;
		scanf("%lld", &input);
		n = input;
		while (n != 2 && n>2) {
			if (n > 2) {
				long long int tmp = sqrt(n);
				if (tmp * tmp == n) {
					n = tmp;
					count++;
				}
				else {
					count = count + ((tmp + 1) * (tmp + 1) - n);
					count++;
					n = tmp + 1;
				}
			}
		}

		printf("#%d %lld\n", i, count);
	}
    return 0;
}

