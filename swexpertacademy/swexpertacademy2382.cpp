#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int mX[5] = { 0, -1 ,1, 0 ,0 };
int mY[5] = { 0, 0, 0, -1, 1 };
typedef struct NODE {
	int x;
	int y;
	int num;
	int d;
}node;

typedef struct NODE_MAP {
	int num = 0;
	int max_num = 0;
	int d = 0;
}m_node;

typedef struct POINT{
	int x;
	int y;
}p;

int dir(int d) {
	if (d == 1)
		return 2;
	if (d == 2)
		return 1;
	if (d == 3)
		return 4;
	if (d == 4)
		return 3;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++) {
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);

		m_node map[100][100] = { };
		vector<node> mi;
		vector<p> pp;
		for (int i = 0; i < K; i++) {
			node tmp;
			scanf("%d %d %d %d", &tmp.x, &tmp.y, &tmp.num, &tmp.d);
			mi.push_back(tmp);
		}
		int ans = 0;

		while (M > 0) {
			M--;

			while(!mi.empty()){
				node tmp = mi.back();
				mi.pop_back();
				tmp.x = tmp.x + mX[tmp.d];
				tmp.y = tmp.y + mY[tmp.d];

				if (tmp.x == 0 || tmp.y == 0 || tmp.x == N - 1 || tmp.y == N - 1) {
					map[tmp.x][tmp.y].num = tmp.num / 2;
					map[tmp.x][tmp.y].max_num = tmp.num;
					map[tmp.x][tmp.y].d = dir(tmp.d);
				}
				else if (map[tmp.x][tmp.y].num == 0) {
					map[tmp.x][tmp.y].num = tmp.num;
					map[tmp.x][tmp.y].max_num = tmp.num;
					map[tmp.x][tmp.y].d = tmp.d;
				}
				else {
					map[tmp.x][tmp.y].num += tmp.num;
					if (map[tmp.x][tmp.y].max_num < tmp.num) {
						map[tmp.x][tmp.y].max_num = tmp.num;
						map[tmp.x][tmp.y].d = tmp.d;
					}
				}
				p pp_tmp;
				pp_tmp.x = tmp.x;
				pp_tmp.y = tmp.y;
				pp.push_back(pp_tmp);
			}
			mi.clear();

			while(!pp.empty()) {
				p pp_tmp = pp.back();
				pp.pop_back();
				if (map[pp_tmp.x][pp_tmp.y].num == 0) {

				}
				else {
					node tmp;
					tmp.x = pp_tmp.x;
					tmp.y = pp_tmp.y;
					tmp.num = map[tmp.x][tmp.y].num;
					tmp.d = map[tmp.x][tmp.y].d;
					mi.push_back(tmp);
					map[tmp.x][tmp.y].num = 0;
				}
			}
			pp.clear();
			 

		}
		for (int i = 0; i < mi.size(); i++) {
			ans += mi.at(i).num;
		}

		


		printf("#%d %d\n", t, ans);
	}
    return 0;
}

