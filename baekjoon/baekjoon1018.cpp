#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;

char Wmap[8][8] = { { 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' } ,
{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' } ,
{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' } };
char Bmap[8][8] = { { 'B','W','B','W','B','W','B','W' } ,{ 'W','B','W','B','W','B','W','B' },
{ 'B','W','B','W','B','W','B','W' } ,{ 'W','B','W','B','W','B','W','B' } ,
{ 'B','W','B','W','B','W','B','W' } ,{ 'W','B','W','B','W','B','W','B' } ,
{ 'B','W','B','W','B','W','B','W' } ,{ 'W','B','W','B','W','B','W','B' } };
vector<vector<char>> map(50, vector<char>(50));

int ans = 65;

int w(int x, int y) {
	int ret = 0;

	for (int i = 0; i <  8; i++) {
		for (int j = 0; j < 8; j++) {

			if (Wmap[i][j] == map[i + x][j + y]) {
				continue;
			}
			else {
				ret++;
			}

			if (ret >= ans) {
				return ret;
			}
		}
	}
	return ret;
}

int b(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			if (Bmap[i][j] == map[i + x][j + y]) {
				continue;
			}
			else {
				ret++;
			}

			if (ret >= ans) {
				return ret;
			}
		}
	}
	return ret;
}

int main()
{
	cin >> N;
	cin >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	
	for (int i = 0; i < N-7; i++) {
		for (int j = 0; j < M-7; j++) {
			ans = min(ans,w(i, j));
			ans = min(ans, b(i, j));
			
		}
	}
	printf("%d\n", ans);
    return 0;

}

