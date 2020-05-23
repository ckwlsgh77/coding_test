#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> king;
pair<int, int> stone;
int N;


int main()
{
	string str1,str2;
	cin >> str1 >> str2 >> N;
	vector<string> cmd(N);
	king = { 8 - (str1[1] - 48),str1[0] - 65 };
	stone = { 8 - (str2[1] - 48), str2[0] - 65 };

	for (int i = 0; i < N; i++) {

		cin >> cmd[i];

		pair<int, int> tmp_king = king;
		pair<int, int> tmp_stone = stone;
		if (cmd[i] == "B") {
			tmp_king.first ++;
			if (tmp_stone.first == tmp_king.first &&tmp_stone.second == tmp_king.second) {
				tmp_stone.first++;
			}
		}
		else if (cmd[i] == "T") {
			tmp_king.first --;
			if (tmp_stone.first == tmp_king.first &&tmp_stone.second == tmp_king.second) {
				tmp_stone.first--;
			}
		}
		else if (cmd[i] == "R") {
			tmp_king.second++;
			if (tmp_stone.first == tmp_king.first &&tmp_stone.second == tmp_king.second) {
				tmp_stone.second++;
			}
		}
		else if (cmd[i] == "L") {
			tmp_king.second --;
			if (tmp_stone.first == tmp_king.first &&tmp_stone.second == tmp_king.second) {
				tmp_stone.second--;
			}
		}
		else if (cmd[i] == "RT") {
			tmp_king.first--;
			tmp_king.second++;
			if (tmp_stone.first == tmp_king.first &&tmp_stone.second == tmp_king.second) {
				tmp_stone.first--;
				tmp_stone.second++;
			}
		}
		else if (cmd[i] == "LT") {
			tmp_king.first--;
			tmp_king.second--;
			if (tmp_stone.first == tmp_king.first &&tmp_stone.second == tmp_king.second) {
				tmp_stone.first--;
				tmp_stone.second--;
			}
		}
		else if (cmd[i] == "RB") {
			tmp_king.first++;
			tmp_king.second++;
			if (tmp_stone.first == tmp_king.first &&tmp_stone.second == tmp_king.second) {
				tmp_stone.first++;
				tmp_stone.second++;
			}
		}
		else if (cmd[i] == "LB") {
			tmp_king.first++;
			tmp_king.second--;
			if (tmp_stone.first == tmp_king.first &&tmp_stone.second == tmp_king.second) {
				tmp_stone.first++;
				tmp_stone.second--;
			}
		}

		if (tmp_king.first >= 0 && tmp_king.first <= 7 && 
			tmp_king.second >= 0 && tmp_king.second <= 7 &&
			tmp_stone.second >= 0 && tmp_stone.second <= 7 &&
			tmp_stone.first >= 0 && tmp_stone.first <= 7) {
			king = tmp_king;
			stone = tmp_stone;
		}

	}

	str1[0] = king.second + 65;
	str1[1] = 8 - king.first + 48;

	str2[0] = stone.second + 65;
	str2[1] = 8 - stone.first + 48;

	cout << str1 << endl  << str2 << endl;
	

    return 0;
}

