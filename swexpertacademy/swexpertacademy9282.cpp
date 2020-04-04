#include <stdio.h>
#include <algorithm>
#include <string.h>

int N, M;
int TC;
int chocolate[51][51] = { 0, };
int dp[51][51][51][51];
int S[51][51];
using namespace std;

int cal(int x, int y, int h, int w) {
	if (h == 1 && w == 1) return 0;

	int &ret = dp[x][y][h][w];
	if (ret != -1) return ret;
	else ret = 999999999;

	// Range(a, b, c, d) = S(dx, dy)−S(sx−1, dy)−S(dx, sy−1) + S(sx−1, sy−1)


	int sum = S[x + h - 1][y + w - 1] - S[x - 1][y + w - 1] - S[x + h - 1][y - 1] + S[x - 1][y - 1];


	for (int i = 1; i < h; i++) {
		ret = min(ret, sum + cal(x, y, i, w) + cal(x + i, y, h - i, w));
	}

	for (int i = 1; i < w; i++) {
		ret = min(ret, sum + cal(x, y, h, i) + cal(x, y + i, h, w - i));
	}

	return ret;
}
#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	/* 아래 코드를 수행하지 않으면 여러분의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	출력한 내용이 실제 표준 출력에 기록되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL); 을 수행하시기 바랍니다.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (int i = 0; i < TC; i++) {

		memset(dp, -1, sizeof(dp));
		memset(S, 0, sizeof(S));

		scanf("%d %d", &N, &M);

		for (int x = 1; x < N + 1; x++) {
			for (int y = 1; y < M + 1; y++) {
				scanf("%d", &chocolate[x][y]);
			}
		}
		for (int a = 1; a < N + 1; a++) {
			for (int b = 1; b < M + 1; b++) {
				S[a][b] = chocolate[a][b] + S[a][b - 1];
			}
		}

		for (int b = 1; b < M + 1; b++) {
			for (int a = 1; a < N + 1; a++) {
				S[a][b] = S[a][b] + S[a - 1][b];
			}
		}


		int ans = 0;
		ans = cal(1, 1, N, M);

		printf("#%d %d\n", i + 1, ans);

	}

	return 0;
}