#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map(21, vector<int>(21, 0));
int N;
int population[21][21];
int ans = 40001;

int make_map(int x, int y, int d1, int d2) {

	int site[6] = { 0, };
/*
	for (int a = 1; a <= d1; a++) {
		if (map[x + a][y - a] == 0) {
			map[x + a][y - a] = 5;
			site[5]+= population[x + a][y - a];
		}
		
		if (map[x +d2+ a][y + d2 - a] == 0) {
			map[x +d2+ a][y + d2 - a] = 5;
			site[5]+= population[x + d2 + a][y + d2 - a];
		}


	}
	for (int b = 1; b <= d2; b++) {
		if (map[x + b][y + b] == 0) {
			map[x + b][y + b] = 5;
			site[5]+= population[x + b][y + b];
		}

		if (map[x +d1+ b][y-d1 + b] == 0) {
			map[x+d1 + b][y-d1 + b] = 5;
			site[5]+= population[x + d1 + b][y - d1 + b];
		}

	}
	*/
	int t1 = 0, t2 = 0; // t1은 d1에 t2는 d2에 대응
	bool bt1 = false, bt2 = false; // 중간에 전환해야 하므로, bool 변수 활용

								   // 5
	for (int r = x; r <= x + d1 + d2; r++)
	{
		for (int c = y - t1; c <= y + t2; c++) {
			map[r][c] = 5;
			site[5] += population[r][c];
		}

		if (!bt1) ++t1;
		else --t1;

		if (!bt2) ++t2;
		else --t2;

		// 도달할 수 있는 만큼 도달했으면, 그 이후로 감소해야 한다.
		if (t1 == d1) bt1 = true;
		if (t2 == d2) bt2 = true;
	}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (r >= 1 && r < x + d1 && c >= 1 && c <= y) {// 1
				if (map[r][c] == 0) {
					map[r][c] = 1;
					site[1]+= population[r][c];
				}
				else if (map[r][c] == 5) {
					continue;
				}
			}
			else if (r >= 1 && r <= x + d2 && c > y && c <= N) { // 2
				if (map[r][c] == 0) {
					map[r][c] = 2;
					site[2]+= population[r][c];
				}
				else if (map[r][c] == 5) {
					continue;
				}
			}
			else if (x + d1 <= r && r <= N && 1 <= c && c < y - d1 + d2) {
				if (map[r][c] == 0) {
					map[r][c] = 3;
					site[3]+= population[r][c];
				}
				else if (map[r][c] == 5) {
					continue;
				}
			}
			else if (x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N) {
				if (map[r][c] == 0) {
					map[r][c] = 4;
					site[4]+= population[r][c];
				}
				else if (map[r][c] == 5) {
					continue;
				}
			}
		}
	}


	int max_ans = 0;
	int min_ans = 40001;
	for (int i = 1; i < 6; i++) {

		if (site[i] == 0)
			return -1;

		max_ans = max(max_ans, site[i]);
		min_ans = min(min_ans, site[i]);
	}

	return max_ans - min_ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d",&population[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int d1 = 1; d1 <= N - 1; d1++) {
				for (int d2 = 1; d2 <= N - 1; d2++) {
					if (i + d1 + d2 <= N && j - d1 >= 1 && j - d1 < j && j < j + d2 && j + d2 <= N) {
						vector<vector<int>> tmp_map = map;
						int tmp_ans = make_map(i, j, d1, d2);
						if (tmp_ans != -1)
							ans = min(ans, tmp_ans);
						map = tmp_map;
					}
				}
			}
		}
	}

	printf("%d\n", ans);
    return 0;
}

