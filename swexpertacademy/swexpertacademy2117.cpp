#include <stdio.h>

typedef struct POINT {
	int x;
	int y;
}point;

point house[400];

int abs(int a, int b) {
	if (a > b) {
		return a - b;
	}
	else if (a < b) {
		return b - a;
	}
	else
		return 0;
}

int distance(int x1, int y1, int x2, int y2) {
	return abs(x1,x2) + abs(y1,y2);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		int N,M;
		int map[20][20] = { 0, };
		scanf("%d %d", &N, &M);
		int house_count = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) {
					house[house_count].x = i;
					house[house_count].y = j;
					house_count++;
				}
			}

		}

		int count;
		int benefit;
		int ans = 0;
		for (int k = 1; k < N * 2; k++) {

			for (int x = 0; x < N; x++) {

				for (int y = 0; y < N; y++) {
					count = 0;
					benefit = 0;
					for (int i = 0; i < house_count; i++) {

						if (distance(x, y, house[i].x, house[i].y) < k) {
							count++;
						}
					}
					benefit = (count * M) - (k * k + (k - 1) * (k - 1));
					if (benefit >= 0) {
						if (ans < count) {
							ans = count;
						}
					}
				}

				
			}

		}
		
		printf("#%d %d\n", t, ans);
	}
    return 0;
}

