#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int mX[4] = { -1, 1, 0, 0 };
int mY[4] = { 0 ,0, -1 , 1 };

int b_5(int D) {

	switch (D) {
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 2;
	}

}

int b_1(int D) {

	switch (D) {
	case 0:
		return 1;
	case 1:
		return 3;
	case 2:
		return 0;
	case 3:
		return 2;
	}
}

int b_2(int D) {

	switch (D) {
	case 0:
		return 3;
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	}
}

int b_3(int D) {

	switch (D) {
	case 0:
		return 2;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 1;
	}
}

int b_4(int D) {

	switch (D) {
	case 0:
		return 1;
	case 1:
		return 2;
	case 2:
		return 3;
	case 3:
		return 0;
	}
}

int main()
{	
	int TC;
	scanf("%d", &TC);
	int map[100][100];

	

	for (int t = 1; t <= TC; t++) {
		int N;
		scanf("%d", &N);
		vector<pair<int, int>> white_hall[5];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					white_hall[map[i][j]- 6].push_back(make_pair(i, j));
				}
			}
		}

		int start_x,start_y;
		int ans = 0;
		int count = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				start_x = i;
				start_y = j;
				if (map[start_x][start_y] == 0) {
					int D;
					for (int k = 0; k < 4; k++) {
						int cur_x = start_x;
						int cur_y = start_y;
						D = k;
						count = 0;
						while (1) {
							//printf("1---(%d,%d) D:%d map:%d\n", cur_x, cur_y, D, map[cur_x][cur_y]);
							cur_x = cur_x + mX[D];
							cur_y = cur_y + mY[D];
						//	printf("2---(%d,%d) D:%d map:%d\n", cur_x, cur_y, D, map[cur_x][cur_y]);
							if ((cur_x<0 || cur_x>=N || cur_y<0 || cur_y >=N)) {
								count++;
								D = b_5(D);
								continue;
							}

							if ((cur_x == start_x && cur_y == start_y) || map[cur_x][cur_y] == -1){
								break;
							}
							else if (map[cur_x][cur_y] == 5) {
								count++;
								D = b_5(D);
							}
							else if (map[cur_x][cur_y] >= 1 && map[cur_x][cur_y] <= 4) {

								switch (map[cur_x][cur_y]) {
								case 1:
									D = b_1(D);
									count++;
									break;
								case 2:
									D = b_2(D);
									count++;
									break;
								case 3:
									D = b_3(D);
									count++;
									break;
								case 4:
									D = b_4(D);
									count++;
									break;
								}
							}
							else if (map[cur_x][cur_y] >= 6 && map[cur_x][cur_y] <= 10) {
								
								if ((cur_x != white_hall[map[cur_x][cur_y] - 6][0].first) || (cur_y != white_hall[map[cur_x][cur_y] - 6][0].second)) {
									int tmp_x = white_hall[map[cur_x][cur_y] - 6][0].first;
									int tmp_y = white_hall[map[cur_x][cur_y] - 6][0].second;
									cur_x = tmp_x;
									cur_y = tmp_y;
								}
								else {
									int tmp_x = white_hall[map[cur_x][cur_y] - 6][1].first;
									int tmp_y = white_hall[map[cur_x][cur_y] - 6][1].second;
									cur_x = tmp_x;
									cur_y = tmp_y;
								}
							}
						}

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

