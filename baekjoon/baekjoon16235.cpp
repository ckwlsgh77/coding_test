#include <stdio.h>
#include <queue>
using namespace std;

int N, M, K;

int energy[11][11];
int a[11][11];

int mx[8] = {-1,-1,-1,0,0,1,1,1};
int my[8] = {-1,0,1,-1,1,-1,0,1};

typedef struct TREE {
	int x;
	int y;
	int age;
}tree;

struct cmp {
	bool operator()(int t, int u) {
		return t > u;
	}
};

deque<int> q[11][11];
queue<tree> dead_tree;
queue<tree> alive_tree;

void spring() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			int len = q[i][j].size();

			for (int k = 0; k < len; k++) {
				int cur = q[i][j].front();
				q[i][j].pop_front();

				if (energy[i][j] >= cur) {
					alive_tree.push({ i,j,cur + 1 });
					energy[i][j] = energy[i][j] - cur;
					
					
				}
				else {
					dead_tree.push({i, j, cur});
				}

			}
		}
	}


}

void summer() {
	while (!dead_tree.empty()) {
		tree tmp = dead_tree.front();
		dead_tree.pop();

		energy[tmp.x][tmp.y] = energy[tmp.x][tmp.y] + (tmp.age / 2);


	}
}

void fall() {

	while (!alive_tree.empty()) {
		tree tmp = alive_tree.front();
		alive_tree.pop();
		q[tmp.x][tmp.y].push_back(tmp.age);
		if ((tmp.age % 5) == 0) {
			for (int i = 0; i < 8; i++) {
				int tmp_x = tmp.x + mx[i];
				int tmp_y = tmp.y + my[i];

				if (tmp_x > 0 && tmp_x <= N && tmp_y > 0 && tmp_y <= N) {
					q[tmp_x][tmp_y].push_front(1);
				}
			}
		}
	}

}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			energy[i][j] += a[i][j];
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d",&a[i][j]);
			energy[i][j] = 5;
			
		}
	}


	for (int i = 0; i < M; i++) {
		int x, y, age;
		scanf("%d %d %d", &x, &y, &age);
		q[x][y].push_back(age);

	}

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();
		
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += q[i][j].size();

		}
	}

	printf("%d\n",ans);
    return 0;
}

