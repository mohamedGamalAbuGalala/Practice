#include "stdafx.h"
// Topo Sort.cpp : Defines the entry point for the console application.
// by :: bu_galala

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> arr[10001];
int cnt[10001], n, m, cur, x, y;
set<int> Ready;
vector<int> res;

int main()
{
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &x, &y);
		arr[x].push_back(y);
		cnt[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!cnt[i])
			Ready.insert(i);
	}
	while (Ready.size()) {
		cur = *Ready.begin();
		Ready.erase(*Ready.begin());
		for (int i = 0; i < arr[cur].size(); i++) {
			cnt[arr[cur][i]]--;
			if (!cnt[arr[cur][i]])
				Ready.insert(arr[cur][i]);
		}
		res.push_back(cur);
	}
	if (res.size() != n)
		printf("Sandro fails. \n");
	else {
		for (int i = 0; i < res.size(); i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	return 0;
}
/*
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6

2 2
1 2
2 1

*/
