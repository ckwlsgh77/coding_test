#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

int main()
{
	int TC;
	scanf("%d",&TC);

	


	for (int turn = 1; turn <= TC; turn++) {

		int up = 1;
		int down = 1;
		int ans = 1;
		scanf("%d", &n);

		for (int arr_num = 0; arr_num < n; arr_num++) {
			scanf("%d", &arr[arr_num]);

			if (arr_num == 0)
				continue;

			if (arr[arr_num] == arr[arr_num - 1]) {
				continue;
			}
			else if (arr[arr_num] > arr[arr_num - 1]) {
				if (down > up) {
					up = 1;
					down = 1;
					ans++;
				}
				else
					up++;
			}
			else {
				if (up > down) {
					up = 1;
					down = 1;
					ans++;
				}
				else
					down++;
			}

		}


		

		
		printf("#%d %d\n", turn, ans);
	}

    return 0;
}

