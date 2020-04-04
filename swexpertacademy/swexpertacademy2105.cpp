#include <stdio.h>

int N;
int map[20][20];
bool visited[20][20] = { 0, };
bool desert_num[101] = { 0, };
int ans;
int start_x, start_y;
int start_d;

int mX[4] = { -1,-1, 1, 1 };
int mY[4] = { -1, 1, -1 ,1 };

bool pos_start(int x, int y) {
	if (x == 0 && y == 0) 
		return false;
	if (x == 0 && y == N - 1)
		return false;
	if (x == N - 1 && y == 0)
		return false;
	if (x == N - 1 && y == N - 1)
		return false;

	return true;
}


void tour(int x, int y, int depth, int angle, int d) {

	if (depth != 0) {
		if (x == start_x && y == start_y) {
			if (angle == 3) {
				if (ans < depth) {
					ans = depth;
				}
			}
			return;
		}
		visited[x][y] = 1;
		desert_num[map[x][y]] = 1;
	}
	

	for (int i = 0; i < 4; i++) {

		if (start_d != d && start_d == i) {
			continue;
		}

		int tmp_x = x + mX[i];
		int tmp_y = y + mY[i];
		if (tmp_x >= 0 && tmp_x < N && tmp_y >= 0 && tmp_y < N) {
			if (visited[tmp_x][tmp_y] == 0 && desert_num[map[tmp_x][tmp_y]] == 0 && angle < 4 ) {

				if (depth == 0) {
					start_d = i;
					tour(tmp_x, tmp_y, depth + 1, angle, i);
				}
				else {

					if (d != i)
						tour(tmp_x, tmp_y, depth + 1, angle + 1, i);
					else
						tour(tmp_x, tmp_y, depth + 1, angle, d);
				}

			}
		}
	}
	visited[x][y] = 0;
	desert_num[map[x][y]] = 0;
	return;
}

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		ans = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (pos_start(i,j)) {
					start_x = i;
					start_y = j;
					tour(i, j, 0, 0, 0);
				}
			}
		}


		if (ans < 4) {
			ans = -1;
		}

		printf("#%d %d\n", t, ans);
	}
    return 0;
}

