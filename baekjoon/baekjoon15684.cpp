#include <stdio.h>
#include <string.h>
int N, M, H;

int map[32][11] = { 0, };
int ans = 9999;

bool pos(int map[32][11]) {
	for (int i = 1; i <= N; i++) {
		int row = 1;
		int col = i;

		while (row < H+1) {
			col = col + map[row][col];
			row = row + 1;
		}

		if (col != i) {
			return false;
		}

	}
	return true;
}


void cal(int row, int depth) {
	if (depth > ans || depth > 3) {
		return;
	}
	
	if (pos(map)) {
		if (ans > depth)
			ans = depth;
		return;
	}

	for (int i = row; i <= H; i++) {
		for (int j = 1; j < N; j++) {

			if (map[i][j] || map[i][j+1]) {
				continue;
			}

			map[i][j] = 1;
			map[i][j + 1] = -1;
			cal(i, depth + 1);
			map[i][j] = 0;
			map[i][j + 1] = 0;

		}
	}

	


}



int main()
{
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		map[a][b] = 1;
		map[a][b+1] = -1;
	}
	
	cal(1, 0);

	if (ans == 9999)
		ans = -1;

	printf("%d\n", ans);
    return 0;
}

