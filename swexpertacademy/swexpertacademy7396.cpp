#include <stdio.h>
#include <vector>
#include <malloc.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int m_x[2] = { 1,0 };
int m_y[2] = { 0, 1 };
int N, M;


int main()
{
	int TC;
	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++) {

		scanf("%d %d", &N, &M);

		char **alphabet = (char**)malloc(sizeof(char*)*N);
		//bool **check = (bool**)malloc(sizeof(bool*)*N);
		for (int i = 0; i < N; i++) {
			alphabet[i] = (char*)malloc(sizeof(char)*(M + 1));
		//	check[i] = (bool*)malloc(sizeof(bool)*M);
			//memset(check[i], 0, sizeof(check[i]));
			scanf("%s", alphabet[i]);
		}


		char *ans;
		ans = (char*)malloc(sizeof(char)*(N + M - 1));
		ans[0] = alphabet[0][0];
		int ans_count = 1;

		queue<pair<int, int>> q;

		q.push(make_pair(0, 0));
		while (1) {
			vector<pair<int, int>> tmp;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (x + 1 < N ) {
					tmp.push_back(make_pair(x + 1, y));
					//check[x + 1][y] = 1;
				}
				if (y + 1 < M) {
					tmp.push_back(make_pair(x, y + 1));
					//check[x][y + 1] == 1;
				}
			}
			tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
			
			if (tmp.size() == 0) {
				break;
			}
			if (tmp[0].first == N - 1 && tmp[0].second == M - 1) {
				ans[ans_count] = alphabet[tmp[0].first][tmp[0].second];
				ans_count++;
				break;
			}

			char tmp_char = alphabet[tmp[0].first][tmp[0].second];
			for (int i = 1; i < tmp.size(); i++) {
				if (tmp_char > alphabet[tmp[i].first][tmp[i].second]) {
					tmp_char = alphabet[tmp[i].first][tmp[i].second];
				}
			}

			ans[ans_count] = tmp_char;
			ans_count++;
			for (int i = 0; i < tmp.size(); i++) {
				if (tmp_char == alphabet[tmp[i].first][tmp[i].second]) {
					q.push(make_pair(tmp[i].first, tmp[i].second));
				}
			}
			tmp.clear();
		}
	


		printf("#%d ", t);
		for (int i = 0; i < ans_count; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");

		for (int i = 0; i < N; i++) {
			free(alphabet[i]);
			//free(check[i]);
		}
		free(alphabet);
	//	free(check);
		
	}
    return 0;
}

