#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int N;
int S[20][20];

int ans = 100001;

void power_cal(int bit) {
	vector<int> team1;
	vector<int> team2;

	int S1 = 0;
	int S2 = 0;

	for (int i = 0; i < N; i++) {
		if (bit & 1 << i) {
			team1.push_back(i);
		}
		else {
			team2.push_back(i);
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			S1 += S[team1[i]][team1[j]];
			S2 += S[team2[i]][team2[j]];
		}
	}


	if (ans > abs(S1 - S2)) {
		ans = abs(S1 - S2);
	}

}

void cal(int depth, int bit) {

	if (depth == N / 2) {
		power_cal(bit);
	}

	if (depth > N / 2)
		return;

	for (int i = 0; i < N; i++) {
		if (!(bit & 1 << i)) {
			cal(depth + 1, bit | 1 << i);
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);

		}
	}

	cal(0, 0);

	printf("%d\n", ans);

	return 0;
}

