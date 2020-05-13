#include <stdio.h>
#include <vector>

using namespace std;

int map[33] = { 0, };
int score[33] = { 0, };
int turn[33] = { 0, };
bool check[33] = { 0 };
int chess[4] = { 0,0,0,0 };
int arr[10] = { 0, };

int ans = 0;
void dfs(int cnt, int sum) {

	if (cnt == 10) {

		if (sum > ans)
			ans = sum;

		return;
	}

	for (int i = 0; i < 4; i++) {

		int prev = chess[i];
		int now = prev;

		int move_count = arr[cnt];

		if (turn[now] > 0) {
			now = turn[now];
			move_count--;
		}

		while (move_count--) {
			now = map[now];
		}

		if (now != 21 && check[now]) continue;

		check[now] = true;
		check[prev] = false;
		chess[i] = now;
		
		dfs(cnt + 1, sum + score[now]);

		check[now] = false;
		check[prev] = true;
		chess[i] = prev;

	}
}

int main()
{
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 27; i++) {
		map[i] = i + 1;
	}
	map[21] = 21; map[30] = 31;
	map[27] = 20; map[31] = 32;
	map[28] = 29; map[32] = 25;
	map[29] = 25;

	turn[5] = 22;
	turn[10] = 28;
	turn[15] = 30;

	for (int i = 0; i < 21; i++) {
		score[i] = i * 2;
	}
	score[22] = 13; score[29] = 24;
	score[23] = 16; score[30] = 28;
	score[24] = 19; score[31] = 27;
	score[25] = 25; score[32] = 26;
	score[26] = 30;
	score[27] = 35;
	score[28] = 22;

	dfs(0, 0);
	
	printf("%d\n", ans);

    return 0;
}

