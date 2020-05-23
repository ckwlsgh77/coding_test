#include <stdio.h>
#include <vector>

using namespace std;

int N;
vector<int> A(101,0);
vector<int> B(101,0);


int main()
{

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		A[a]++;
	}
	for (int i = 0; i < N; i++) {
		int b;
		scanf("%d", &b);
		B[b]++;
	}

	int S = 0;

	for (int i = 0; i < N; i++) {
		int a = 0;
		int b = 100;

		
		
		while (A[a] == 0) {
			a++;
		}
		int a_tmp = A[a];
		A[a]--;

		while (B[b] == 0) {
			b--;
		}
		int b_tmp = B[b];
		B[b]--;

		S = S + a*b;
	}

	printf("%d\n", S);
    return 0;
}

