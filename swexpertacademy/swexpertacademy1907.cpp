#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <malloc.h>

using namespace std;

int map[1000][1000] = { 0, };
int N, M;
int mX[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int mY[8] = { -1 , 0, 1, -1, 1, -1, 0, 1 };


int check( int x, int y ){

	int count=0;
	for (int i = 0; i < 8; i++) {
		
		int mx = x + mX[i];
		int my = y + mY[i];

		if (map[mx][my] == 0)
			count++;

	}

	return count;
}

int main()
{
	
	int TC;
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		
		scanf("%d %d", &N, &M);
		queue<pair<int, int>> sand;

		for (int i = 0; i < N; i++) {
			char *a = (char*)malloc(sizeof(char)*(M+1));

			scanf("%s", a);

			for (int j = 0; j < M; j++) {

				if (a[j] == '.') {
					map[i][j] = 0;
					sand.push(make_pair(i, j));
				}
				else {
					map[i][j] = a[j] - 48;
				}
			}
			free(a);

		}





		bool change = true;
		int ans = 0;

		while (int s = sand.size()) {

			while (s--) {
				int x = sand.front().first;
				int y = sand.front().second;
				sand.pop();

				for (int i = 0; i < 8; i++) {
					int mx = x + mX[i];
					int my = y + mY[i];

					if (mx >= 0 && mx < N && my >= 0 && my < N) {
						if (map[mx][my]) {
							map[mx][my]--;
							if (!map[mx][my]) {
								sand.push(make_pair(mx, my));
							}
						}
					}
				}

			}
			ans++;

		}

		


		printf("#%d %d\n", t, ans-1);
	}
    return 0;
}

