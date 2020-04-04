#include <stdio.h>
#include <malloc.h>
#include <string.h>

using namespace std;

int D, W, K;
int max_med;
int **map;

bool check(int num) {
	int prev;
	for (int i = 0; i < W; i++) {
		int count = 0;
		for (int j = 0; j < D; j++) {

			if (j == 0) {
				prev = map[j][i];
				count = 1;
			}
			else {
				if (prev != map[j][i]) {
					count = 1;
					prev = map[j][i];
				}
				else {
					count++;
				}
			}

			if (count == K) {
				break;
			}

		}
		if (count == K) {
			continue;
		}
		else
			return false;
	}
	if (max_med > num) {
		max_med = num;
	}


	return true;
}
void spread(int i, int val) {

	for (int j = 0; j < W; j++) {
		map[i][j] = val;
	}
}




void change_map(int start, int use_med) {
	if (use_med > max_med) {
		return;
	}

	if (start >= D) {
		check(use_med);
		return;
	}

	change_map(start + 1, use_med);

	int *tmp = (int*)malloc(sizeof(int)*W);
	for (int i = 0; i < W; i++) {
		tmp[i] = map[start][i];
	}

	spread(start, 0);
	change_map(start + 1, use_med+1);


	spread(start, 1);
	change_map(start + 1, use_med + 1);

	for (int i = 0; i < W; i++) {
		map[start][i] = tmp[i];
	}

	free(tmp);
	return;
}

int main()
{
	int TC;
	scanf("%d", &TC);


	for (int t = 1; t <= TC; t++) {
		
		scanf("%d %d %d", &D, &W, &K);
		int ans = 0;
		max_med = 9999;
		
		map = (int**)malloc(sizeof(int*)*D);
		for (int i = 0; i < D; i++) {
			map[i] = (int*)malloc(sizeof(int)*W);
		}

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d",&map[i][j]);
			}
		}
		if (check(0)) {
			ans = 0;
		}
		else {
			change_map(0,0);
			ans = max_med;
		}
		
		printf("#%d %d\n", t, ans);

		for (int i = 0; i < D; i++) {
			free(map[i]);
		}
		free(map);
	}
    return 0;
}

