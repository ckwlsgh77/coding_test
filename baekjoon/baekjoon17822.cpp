#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;
int N, M, T;

void injub(vector<int> circle[51]) {

	bool visited[51][51] = { 0, };
	int mX[4] = { 0,0,1,-1 };
	int mY[4] = { 1,-1,0,0, };
	bool check = false;
	double sum = 0;
	double sum_count = 0;

	for (int x = 1; x <= N; x++) {
		for (int y = 0; y < M; y++) {
			queue<pair<int, int>> q;
			int tmp_num = 0;

			if (circle[x][y] != 0 && visited[x][y] == 0) {
				q.push({ x,y});
				visited[x][y] = 1;
				sum += circle[x][y];
				sum_count++;
				tmp_num = circle[x][y];
			}
			 

			while (!q.empty()) {
				int tmp_x = q.front().first;
				int tmp_y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int mx = tmp_x + mX[i];
					int my = (tmp_y + mY[i] + M) % M;

					if (mx >= 1 && mx <= N && my >= 0 && my < M) {
						if (circle[mx][my] == tmp_num && visited[mx][my] == 0 ) {
							q.push({ mx,my});
							visited[mx][my] = 1;
							circle[tmp_x][tmp_y] = 0;
							circle[mx][my] = 0;
							check = true;
						}

					}
				}

			}
		}
	}

	if (sum_count != 0) {

		double avg = sum / sum_count;

			if (check == false) {

				for (int x = 1; x <= N; x++) {
					for (int y = 0; y < M; y++) {
						if (circle[x][y] != 0) {
							if (circle[x][y] > avg) {
								circle[x][y] -= 1;
							}
							else if (circle[x][y] < avg) {
								circle[x][y] += 1;
							}
						}
					}
				}
			}
	}
	 
}
void dol(int dir, int num , vector<int> circle[51]) {

	vector<int> tmp(M+1, 0);

	if (dir == 0) {
		tmp[0] = circle[num][M-1];
		for (int i = 0; i < M-1; i++) {
			tmp[i + 1] = circle[num][i];

			
		}
		for (int i = 0; i < M; i++) {
			circle[num][i] = tmp[i];
		}


	}
	else if (dir == 1) {
		tmp[M-1] = circle[num][0];

		for (int i = 0; i < M-1; i++) {
			tmp[i] = circle[num][i + 1];
		}

		for (int i = 0; i < M; i++) {
			circle[num][i] = tmp[i];
		}
	}

}

int main()
{
	
	scanf("%d %d %d", &N, &M, &T);
	
	vector<int> circle[51];
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			scanf("%d", &num);
			circle[i].push_back(num);
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);

		for (int num = x; num <= N; num += x) {
			for (int k_count = 0; k_count < k; k_count++) {
				dol(d, num,circle);
			}
		}		
		injub(circle);
	
	}

	int ans = 0;
	for (int x = 1; x <= N; x++) {
		for (int y = 0; y < M; y++) {
			ans += circle[x][y];
		}
	}

	printf("%d\n", ans);

    return 0;
}

