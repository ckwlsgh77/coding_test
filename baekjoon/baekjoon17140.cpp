#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, k;
int row_count = 3, col_count = 3;
int ans = 0;

vector<vector<int>> map(200,vector<int>(200,0));

struct cmp {
	bool operator()(pair<int, int> t, pair<int, int> u) {

		
		if (t.second == u.second)
			return t.first > u.first;
		else
			return t.second > u.second;
	}
};

int main()
{
	scanf("%d %d %d", &r, &c, &k);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d",&map[i][j]);
		}
	}

	while (map[r - 1][c - 1] != k) {
		ans++;
		if (ans > 100) {
			ans = -1;
			break;
		}
		if (row_count >= col_count) { // 행 정렬
			
			int tmp_col=0;
			for (int x = 0; x < row_count; x++) {
				vector<int> new_arr;
				vector<int> candidate;
				priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
				int num_count[101] = { 0, };

				for (int y = 0; y < col_count; y++) {
					int tmp = map[x][y];
					if (tmp == 0)
						continue;

					if (num_count[tmp] == 0) {
						candidate.push_back(tmp);
					}

					num_count[tmp]++;

				}
				for (int w = 0; w < candidate.size(); w++) {
					pq.push({ candidate[w],num_count[candidate[w]] });
				}

				while (!pq.empty()) {
					new_arr.push_back(pq.top().first);
					new_arr.push_back(pq.top().second);
					pq.pop();
				}

				

				for (int y = 0; y < new_arr.size(); y++) {
					map[x][y] = new_arr[y];
				}
				
				
				for (int y = new_arr.size(); y < col_count * 2; y++) {
					if (y > 100)
						break;
					map[x][y] = 0;
				}
				int u = new_arr.size();
				tmp_col = max(tmp_col, u);
				col_count = max(col_count, tmp_col);
			}
			
		}
		else if (row_count < col_count) { // 열 정렬
			int tmp_row = 0;
			for (int y = 0; y < col_count; y++) {
				vector<int> new_arr;
				vector<int> candidate;
				priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
				int num_count[101] = { 0, };

				for (int x = 0; x < row_count; x++) {
					int tmp = map[x][y];
					if (tmp == 0)
						continue;

					if (num_count[tmp] == 0) {
						candidate.push_back(tmp);
					}

					num_count[tmp]++;

				}
				for (int w = 0; w < candidate.size(); w++) {
					pq.push({ candidate[w],num_count[candidate[w]] });
				}

				while (!pq.empty()) {
					new_arr.push_back(pq.top().first);
					new_arr.push_back(pq.top().second);
					pq.pop();
				}

				

				for (int x = 0; x < new_arr.size(); x++) {
					map[x][y] = new_arr[x];
				}

				
				for (int x = new_arr.size(); x<row_count * 2; x++) {
					if (x > 100)
						break;
					map[x][y] = 0;
				}

				
				int u = new_arr.size();
				tmp_row = max(tmp_row, u);
				row_count = max(row_count, tmp_row);
			}
			
		}

	}

	printf("%d\n", ans);
    return 0;
}

