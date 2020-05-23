#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int N, M, D;

int dist(pair<int, int> x, pair<int, int> y) {

	return abs(x.first - y.first) + abs(x.second - y.second);
}

int main()
{
	scanf("%d %d %d", &N, &M, &D);
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<pair<int, int>> enermy_pos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1) {
				enermy_pos.push_back({ i,j });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < pow(2,M)+1; i++) {

		vector<pair<int, int>> archer_pos;
		for (int j = 0; j < M; j++) {

			if ((i & (1 << j))) {
				archer_pos.push_back({ N,j });
			}

			if (archer_pos.size() > 3)
				break;
		}

		if (archer_pos.size() != 3)
			continue;

		vector<pair<int, int>> tmp_enermy = enermy_pos;
		int tmp_ans = 0;

		while (tmp_enermy.size() > 0) {

			vector<int> idx(3,-1);
			for (int a = 0; a < archer_pos.size(); a++) {
				for (int k = 0; k < tmp_enermy.size(); k++) {

					int e2 = dist(archer_pos[a], tmp_enermy[k]);

					if (idx[a] == -1) {
						if (e2 <= D) {
							idx[a] = k;
							
						}
						continue;
					}
					
					
					int e1 = dist(tmp_enermy[idx[a]], archer_pos[a]);
					
					if (e2 > D)
						continue;

					if (e1 > e2) {
						idx[a] = k;
					}
					else if (e1 == e2) {
						if (tmp_enermy[idx[a]].second > tmp_enermy[k].second) {
							idx[a] = k;
						}

					}
				}

			}

			vector<pair<int, int>> tmp2_enermy;
			for (int k = 0; k < tmp_enermy.size(); k++) {
				bool c = true;
				for (int ix = 0; ix < 3; ix++) {
				
					if (idx[ix] == k) {
						c = false;
						tmp_ans++;
						break;	
					}
				}



				if (c) {
					int x = tmp_enermy[k].first;
					int y = tmp_enermy[k].second;

					if (x + 1 < N) {
						tmp2_enermy.push_back({ x + 1,y });
					}
				}

			}
			tmp_enermy.clear();
			tmp_enermy = tmp2_enermy;

		}

		if (tmp_ans > ans)
			ans = tmp_ans;
	}

	printf("%d\n", ans);
    return 0;
}

