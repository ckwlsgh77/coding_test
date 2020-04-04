#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[300030];
int disc[300030];
int minn[300030];

int main() {
	
	int tc; scanf(" %d", &tc);
	for(int c = 1; c<= tc; c++)  {
		memset(arr, 0, sizeof(arr));
		memset(disc, 0, sizeof(disc));
		memset(minn, 0, sizeof(minn));

		int n, q; scanf(" %d %d", &n, &q);

		for (int i = 0; i<n; i++) 
			scanf(" %d", &arr[i]);

		for (int i = 0; i<q; i++) 
			scanf(" %d", &disc[i]);

		int temp = 99999999;

		for (int i = 0; i<n; i++) {
			temp = min(temp, arr[i]);
			minn[i] = temp;
		}

		reverse(minn, minn + n);

		int pos = 0;
		int ans = 0;
		bool check = true;

		for (int i = 0; i<q; i++) {
			while (pos < n && (minn[pos] < disc[i])) pos++;
			if (pos == n) {
				check = false; break;
			}
			ans = ++pos;
		}

		ans = (check) ? n - ans + 1 : 0;
		printf("#%d %d\n", c, ans);
	}
}
