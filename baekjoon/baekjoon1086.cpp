#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

int N, K;

string str[16];
int a[16];
int len[16];
long long d[1 << 15][101];
int ten[51];

long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> str[i];
		len[i] = str[i].size();
	}

	scanf("%d", &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < len[i]; j++) {
			a[i] = a[i] * 10 + (str[i][j] - '0');
			a[i] = a[i] % K;
		}
	}
	ten[0] = 1;

	for (int i = 1; i < 51; i++) {
		ten[i] = ten[i - 1] * 10;
		ten[i] = ten[i] % K;
	}
	d[0][0] = 1;
	for (int i = 0; i < 1 << N; i++) {
		for (int j = 0; j < K; j++) {
			for (int l = 0; l < N; l++) {
				if ((i & 1 << l) == 0) {
					
					int next = ((j*ten[len[l]]) % K + a[l] % K) % K;
					d[i | 1 << l][next] += d[i][j];
				}
			}
		}
	}
	long long t1 = d[(1 << N) - 1][0];
	long long t2 = 1;
	for (long long i = 2; i <= N; i++) {
		t2 = t2 * i;
	}
	long long g = gcd(t1, t2);
	t1 = t1 / g;
	t2 = t2 / g;

	printf("%lld/%lld\n", t1, t2);

    return 0;
}

