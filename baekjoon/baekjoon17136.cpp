#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> map(10, vector<int>(10, 0));
int ans = 100;
int p[6] = { 0,5,5,5,5,5 };
int paper = 0;
void func(int x, int y) {

	if (y == 10) {
		func(x + 1, 0);
		return;
	}

	if (x == 10) {

		if (ans > paper) {
			ans = paper;
		}
		return;
	}

	if (map[x][y] == 0) {
		func(x, y + 1);
		return;
	}


	for (int k = 5; k >= 1; k--) {

		if (p[k] == 0 || x + k > 10 || y + k > 10) {

			continue;
		}
		bool t = true;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {

				if (map[i + x][j + y] == 0) {

					t = false;
				}
			}
			if (t == 0)
				break;
		}

		if (t == 0)
			continue;


		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				map[i + x][j + y] = 0;				
			}
		}

		p[k]--;
		paper++;

		func(x, y + k);

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				map[i + x][j + y] = 1;
			}
		}

		p[k]++;
		paper--;
	}

}

int main()
{
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	
	func(0, 0);
	if (ans != 100)
		printf("%d\n", ans);
	else
		printf("-1");
    return 0;
}

