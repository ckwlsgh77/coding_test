#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K;
int ans = 0;
vector<int> ch(26, 2);
vector<string> str(50);
string mid_word;
void cal_ans() {
	int tmp_ans = 0;
	for (int i = 0; i < N; i++) {
		bool t = true;

		for (int j = 0; j < str[i].size(); j++) {

			if (ch[str[i][j] - 97] != 1) {
				t = false;
				break;
			}

			
		}
		if (t) {
			tmp_ans++;
		}
	}

	if (tmp_ans > ans)
		ans = tmp_ans;

	return;
}

void func(int count,int start) {

	
	cal_ans();
	if (count == 0) {
		return;
	}

	for (int i = start; i < mid_word.size(); i++) {

		if (ch[mid_word[i] - 97] == 0) {
			ch[mid_word[i] - 97] = 1;
			func(count - 1,i+1);
			ch[mid_word[i] - 97] = 0;
		}

	}

}

int main()
{
	cin >> N;
	cin >> K;
	


	
	

		ch['a' - 97] = 1;
		ch['c' - 97] = 1;
		ch['i' - 97] = 1;
		ch['t' - 97] = 1;
		ch['n' - 97] = 1;

		for (int i = 0; i < N; i++) {
			string tmp_str;
			cin >> tmp_str;

			for (int j = 4; j < tmp_str.size() - 4; j++) {
				str[i].push_back(tmp_str[j]);
				if (ch[tmp_str[j] - 97] == 2) {
					mid_word += tmp_str[j];
					ch[tmp_str[j] - 97] = 0;
				}
				
			}
		}
		

	if(K<5)
		ans = 0;
	else
		func(K-5,0);
	

	printf("%d\n", ans);
    return 0;
}

