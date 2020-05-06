#include "stdio.h"
#include <vector>

using namespace std;
bool map[101][101] = { 0, };
int N;

int mX[4] = { 1,0,-1,0 };
int mY[4] = { 0,-1,0,1 };

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y, d, g;

		scanf("%d %d %d %d", &x, &y, &d, &g);
		int count = 0;
		map[y][x] = 1;
		vector<int> dragon;

		dragon.push_back(d);
		x = x + mX[d];
		y = y + mY[d];
		if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
			map[y][x] = 1;
		}
		

		while (count < g) {

			int vec_size = dragon.size();
			for (int j = vec_size; j > 0; j--) {

				d = (dragon[j - 1] + 1) % 4;
				x = x + mX[d];
				y = y + mY[d];
				if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
					map[y][x] = 1;
				}
				dragon.push_back(d);
			}
			
			count++;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				if (map[i][j + 1] == 1) {
					if (map[i + 1][j] == 1) {
						if (map[i + 1][j + 1] == 1) {
							ans++;
						}
					}
				}
			}

		}
	}

	printf("%d\n", ans);
    return 0;
}

