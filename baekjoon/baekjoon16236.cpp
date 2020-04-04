#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N;
int map[20][20] = { 0, };


int x, y;

int mx[4] = { -1, 1, 0,0 };
int my[4] = { 0,0,-1,1 };

typedef struct point {
	int x;
	int y;
	int depth;
}p;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}

	bool stop = true;
	int ans = 0;
	int cur_lv = 2;
	int eat_count = 0;

	while (stop) {
		bool visited[20][20] = { 0, };
		queue<p> q;
		vector<p> v;
		q.push({ x,y,0});
		int cur_x = x;
		int cur_y = y;
		
		int depth = 0;



		if (eat_count == cur_lv) {
			cur_lv++;
			eat_count = 0;
		}

		while (!q.empty()) {
			p tmp = q.front();
			visited[tmp.x][tmp.y] = 1;
			q.pop();

			if (tmp.depth != depth) {
				int fish_x = 9999;
				int fish_y = 9999;
				depth = tmp.depth;
				for (int i = 0; i < v.size(); i++) {
					p vtmp = v[i];
					if (vtmp.x < fish_x) {
						fish_x = vtmp.x;
						fish_y = vtmp.y;
					}
					else if (vtmp.x == fish_x && vtmp.y < fish_y) {
						fish_x = vtmp.x;
						fish_y = vtmp.y;
					}	
				}

				if (v.size() > 0) {
					map[x][y] = 0;
					x = fish_x;
					y = fish_y;
					map[x][y] = 0;
					eat_count++;
					ans += tmp.depth;
					while (!q.empty()) q.pop();
					v.clear();
					break;
				}
				
			}

			for (int i = 0; i < 4; i++) {
				int tmp_x = tmp.x + mx[i];
				int tmp_y = tmp.y + my[i];
				if (tmp_x >= 0 && tmp_x < N && tmp_y >= 0 && tmp_y < N && visited[tmp_x][tmp_y] == 0) {
					if (map[tmp_x][tmp_y] < cur_lv) {
						if (map[tmp_x][tmp_y] > 0) {
							v.push_back({ tmp_x,tmp_y,depth + 1 });
							visited[tmp_x][tmp_y] = 1;
							q.push({ tmp_x,tmp_y,tmp.depth + 1 });
						}
						else {
							visited[tmp_x][tmp_y] = 1;
							q.push({ tmp_x,tmp_y,tmp.depth+1 });
						}
					}
					else if(map[tmp_x][tmp_y] == cur_lv) {
						visited[tmp_x][tmp_y] = 1;
						q.push({ tmp_x,tmp_y,tmp.depth + 1 });
					}
				}
			}
		}
		
		if (cur_x == x && cur_y == y) {
			break;
		}

	}

	printf("%d\n", ans);
    return 0;
}

