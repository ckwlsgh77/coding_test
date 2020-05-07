#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	long long N;
	

	while (1) {
		long long ans = 0;
		scanf("%lld", &N);

		if (N == 0)
			return 0;
		
		vector<long long> num;
		stack<int> s;

		for (int i = 0; i < N; i++) {
			long long tmp;
			scanf("%lld", &tmp);
			num.push_back(tmp);
		}

		for (long long i = 0; i < N; i++) {
			
			while (!s.empty() && num[s.top()] > num[i]) {
				long long height = num[s.top()];
				s.pop();
				long long width = i;
				if (!s.empty()) {
					width = (i - 1 - s.top());
				}
				if (ans < height * width) {
					ans = height * width;
				}

			}

			s.push(i);

		}

		while (!s.empty()) {
			long long height = num[s.top()];
			s.pop();
			long long width = N;
			if (!s.empty()) {
				width = (N - 1 - s.top());
			}
			if (ans < height * width) {
				ans = height * width;
			}
		}

		printf("%lld\n", ans);

		num.clear();
	}
    return 0;
}

