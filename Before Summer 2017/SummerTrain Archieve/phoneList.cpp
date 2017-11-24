// phoneList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

string arr[10000];
int n;
vector< vector<int> > trie;
vector<int> node(10, -1);
bool flag[100000];

int main() {
	int T, cur;
	bool ans, tmp;
	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%d\n", &n);
		for (int i = 0; i < n; i++) {
			getline(cin, arr[i]);
		}
		trie.clear();
		ans = 1;
		trie.push_back(node);
		memset(flag, 0, sizeof flag);
		for (int i = 0; i < n; i++) {
			cur = 0, tmp = 0;
			for (int j = 0; j < arr[i].size(); j++) {
				int digit = arr[i][j] - '0';
				if (trie[cur][digit] != -1)
					cur = trie[cur][digit];
				else {
					trie[cur][digit] = trie.size();
					cur = trie.size();
					trie.push_back(node);
					tmp = 1;
				}
				if (flag[cur])	ans = 0;
			}
			if (tmp == 0)	ans = 0;
			flag[cur] = 1;
		}
		if (ans == 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

