#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

extern void init(void);

extern void insert(int buffer_size, char *buf);

extern int query(int buffer_size, char *buf);


int main(void) {
	freopen("input.txt", "r", stdin);
	int TestCase;
	for (scanf("%d", &TestCase); TestCase--;) {
		int Query_N;
		scanf("%d", &Query_N);

		init();

		static int tc = 0;
		printf("#%d", ++tc);

		for (int i = 1; i <= Query_N; i++) {
			int type; scanf("%d", &type);

			if (type == 1) {
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				insert(buffer_size, buf);
			}
			else {
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
		fflush(stdout);
	}
}


typedef struct NODE {
	int cnt[26];
	bool finish;
	NODE *next[26];
}node;

void delnode(node *del) {
	node *tmp = del;
	for (int i = 0; i < 26; i++) {
		if (tmp->next[i]) {
			delnode(tmp->next[i]);
		}
	}
	free(tmp);
	return;
}


node *makenewnode() {
	node *tmp = (node*)malloc(sizeof(node));

	for (int i = 0; i < 26; i++) {
		tmp->cnt[i] = 0;
		tmp->next[i] = 0;
	}
	tmp->finish = false;

	return tmp;
}

node *root = makenewnode();

void init(void) {
	node *tmp = root;
	delnode(tmp);
	node *root = makenewnode();
	return;
}

void insert(int buffer_size, char *buf) {
	node *tmp = root;
	for (int i = 0; i < buffer_size; i++) {
		if (!tmp->next[buf[i] - 'a'])
			tmp->next[buf[i] - 'a'] = makenewnode();
		tmp->cnt[buf[i]-'a']++;
		tmp = tmp->next[buf[i] - 'a'];
	}
	tmp->finish = true;
}

int query(int buffer_size, char *buf) {
	node *tmp = root;
	for (int i = 0; i < buffer_size - 1; i++) {
		if (!tmp->next[buf[i] - 'a'])
			return 0;
		else
			tmp = tmp->next[buf[i] - 'a'];
	}
	return tmp->cnt[buf[buffer_size - 1] - 'a'];
}