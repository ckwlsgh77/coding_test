#include <stdio.h>
#include <vector>

using namespace std;

int mX[4] = { 0, 0, -1, 1 };
int mY[4] = { 1, -1, 0, 0 };

typedef struct NODE {
	int x;
	int y;
	int dir;
	int energy;
}node;
int visited[4001][4001] = { 0, };


int main()
{
	int TC=0;
	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++) {
		int N=0;
		int ans = 0;
		scanf("%d", &N);
		
		vector<node> atom;
		for (int j = 0; j < N; j++) {
			node tmp;
			tmp.x = 0;
			tmp.y = 0;
			tmp.dir = 0;
			tmp.energy = 0;
			scanf("%d %d %d %d", &tmp.x, &tmp.y, &tmp.dir, &tmp.energy);


			tmp.x = tmp.x + 1000;
			tmp.y = tmp.y + 1000;
			tmp.x = tmp.x * 2;
			tmp.y = tmp.y * 2;


			atom.push_back(tmp);
		}
		

		while (!atom.empty()) {
			
			for (int i = 0; i < atom.size(); i++) {
				visited[atom[i].y][atom[i].x] = 0;
				node tmp = atom[i];

				tmp.x = tmp.x + mX[tmp.dir];
				tmp.y = tmp.y + mY[tmp.dir];

				if (tmp.x < 0 || tmp.x > 4000 || tmp.y < 0 || tmp.y > 4000) {
					tmp.energy = 0;
				}
				else {
					visited[tmp.y][tmp.x] += tmp.energy;
				}
				
				atom[i] = tmp;
			}

			for (int i = 0; i < atom.size(); i++) {
				node tmp = atom[i];

				if (tmp.energy != 0) {
					if (visited[tmp.y][tmp.x] != tmp.energy) {
						ans += visited[tmp.y][tmp.x];
						visited[tmp.y][tmp.x] = 0;
						tmp.energy = 0;
					}
					else {
						visited[tmp.y][tmp.x] = 0;
					}
					
				}

				atom[i] = tmp;

			}

			vector<node> tempVector;
			tempVector.assign(atom.begin(), atom.end());
			atom.clear();
			int tempVectorSize = (int)tempVector.size();
			for (int i = 0; i < tempVectorSize; i++) {
				if (tempVector[i].energy != 0) {
					atom.push_back(tempVector[i]);
				}
			}


		}
		
		printf("#%d %d\n", t, ans);
	}
	
    return 0;
}

