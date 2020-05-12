#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int king = 0;
int map[101][101] = { 0, };
vector<pair<int, int>> shark;
vector<int> speed;
vector<int> shark_size;
vector<int> dir;
vector<bool> check;
int mX[5] = { 0,-1,1,0,0 };
int mY[5] = { 0, 0,0, 1, -1 };
int R, C, M;
int main()
{
	scanf("%d %d %d", &R, &C, &M);

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);

		shark.push_back({r,c});
		speed.push_back(s);
		shark_size.push_back(z);
		dir.push_back(d);
		check.push_back(0);
		
		map[r][c] = i+1;
	}

	int king_index = 0;
	int ans = 0;
	for (int i = 0; i < C; i++) {
		king_index++;

		for (int j = 1; j < R+1; j++) {
			if (map[j][king_index]) {
				int shark_idx = map[j][king_index] - 1;
				ans += shark_size[shark_idx];
				map[j][king_index] = 0;
				check[shark_idx] = 1;
				break;
			}
			else
				continue;

		}
		
		for (int j = 0; j < shark.size(); j++) {
			if (check[j] == 1) {
				continue;
			}
			else {
				map[shark[j].first][shark[j].second] = 0;
				int mx = shark[j].first + mX[dir[j]] * speed[j];
				int my = shark[j].second + mY[dir[j]] * speed[j];

				while (mx < 1 || mx > R) {

					if (mx < 1) {
						mx = 1 + abs(1 - mx);

						switch (dir[j]) {
						case 1:
							dir[j] = 2;
							break;
						case 2:
							dir[j] = 1;
							break;
						}

					}
					else if (mx > R) {
						mx = R - abs(R - mx);

						switch (dir[j]) {
						case 1:
							dir[j] = 2;
							break;
						case 2:
							dir[j] = 1;
							break;
						}
					}

				}

				while (my <1 || my >C) {
					if (my < 1) {
						my = 1 + abs(1 - my);

						switch (dir[j]) {
						case 3:
							dir[j] = 4;
							break;
						case 4:
							dir[j] = 3;
							break;
						}
					}
					else if (my > C) {
						my = C - abs(C - my);

						switch (dir[j]) {
						case 3:
							dir[j] = 4;
							break;
						case 4:
							dir[j] = 3;
							break;
						}
					}
				}
				shark[j].first = mx;
				shark[j].second = my;
			}

		}
		for (int j = 0; j < shark.size(); j++) {
			if (check[j] == 0) {		
				if (map[shark[j].first][shark[j].second] == 0) {
					map[shark[j].first][shark[j].second] = j+1;
				}

				else {
					int shark_idx = map[shark[j].first][shark[j].second] - 1;
					if (shark_size[shark_idx] < shark_size[j]) {
						check[shark_idx] = 1;

						map[shark[j].first][shark[j].second] = j + 1;
						
					}
					else {
						check[j] = 1;
					}
				}
			}
		}
	//	printf("----%d\n",king_index);
//		for (int x = 1; x < R + 1; x++) {
	//		for (int y = 1; y < C + 1; y++) {
	//			printf("%d ", map[x][y]);
		//	}
	//		printf("\n");
	//	}
	}


	printf("%d\n",ans);

    return 0;
}

