#include <stdio.h>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int stair[146];



int small(int a, int b){
	int ret = 0;

	int a_x, a_y, b_x, b_y;

	for (int i = 1; i <= 145; i++) {
		if (stair[i] > a) {
			a_x = i - 1;
			break;
		}
	}

	for (int i = 1; i <= 145; i++) {
		if (stair[i] > b) {
			b_x = i - 1;
			break;
		}
	}

	a_y = a - stair[a_x];
	b_y = b - stair[b_x];

	if (a_x == b_x) {
		ret = abs(a_y - b_y);
	}
	else if (a_y == b_y) {
		ret = abs(a_x - b_x);
	}
	else {
		if (a_y > b_y) {
			ret = abs(a_x - b_x) + abs(a_y - b_y);
		}
		else if (a_y < b_y) {
			ret = min(abs(a_x - b_x), abs(a_y - b_y)) + abs(abs(a_x - b_x) - abs(a_y - b_y));
		}
	}



	return ret;
}

int main()
{
	int x = 1, y = 1;

	int sum = 1;
	for (int i = 1; i <= 145; i++) {
		stair[i] = sum;
		sum += i;
	}

	int TC;
	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++) {
		int a, b;
		scanf("%d %d", &a, &b);

		int ans;
		a > b ? ans = small(b, a) : ans = small(a, b);


		printf("#%d %d\n", t, ans);
	}
    return 0;
}

