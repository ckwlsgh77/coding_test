#include <stdio.h>

int N, M;
int map[50][50] = { 0, };
int dir = 0;
int x, y;
int mx[4] = { -1,0,1,0 };
int my[4] = { 0,1,0,-1 };


int dir_rot(int d) {
	if (d == 0) {
		return 3;
	}
	else if (d == 1) {
		return 0;
	}
	else if (d == 2) {
		return 1;
	}
	else if (d == 3) {
		return 2;
	}
}

int dir_back(int d) {
	if (d == 0) {
		return 2;
	}
	else if (d == 1) {
		return 3;
	}
	else if (d == 2) {
		return 0;
	}
	else if (d == 3) {
		return 1;
	}
}

int main()
{
	scanf("%d %d ", &N, &M);
	scanf("%d %d %d", &x, &y, &dir);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int ans = 0;
	bool stop = true;
	int dir_count = 0;
	bool num1 = true;

	while (stop) {

		if (num1) {
			map[x][y] = 2;
			ans++;
		}
		else if (dir_count == 4) {
			int tmp_dir = dir_back(dir);
			int tmp_x = x + mx[tmp_dir];
			int tmp_y = y + my[tmp_dir];

			if (map[tmp_x][tmp_y] == 0 || map[tmp_x][tmp_y] == 2) {
				x = tmp_x;
				y = tmp_y;
				dir_count = 0;
			}
			else {
				stop = false;
			}

		}
		


		dir = dir_rot(dir);

		int tmp_x = x + mx[dir];
		int tmp_y = y + my[dir];

		if (map[tmp_x][tmp_y] == 0) {
			x = tmp_x;
			y = tmp_y;
			dir_count = 0;
			num1 = true;
			continue;
		}
		else {
			dir_count++;
			num1 = false;
			continue;
		}



	}

	printf("%d\n", ans);
    return 0;
}

