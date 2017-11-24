#include "stdafx.h"
// VertexCover.cpp : Defines the entry point for the console application.
// by :: abu_galala

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr[100001];
int memo[100001][2];

int solve(int node, int parent, bool flag) {
	if (arr[node].size() == 1 && arr[node][0] == parent) return !(flag);
	if (memo[node][flag] != -1) return memo[node][flag];
	int ret1 = 1, ret2 = 0;
	for (int i = 0; i < arr[node].size(); i++) {
		if (arr[node][i] == parent) continue;
		ret1 += solve(arr[node][i], node, 1);
		if (flag) ret2 += solve(arr[node][i], node, 0);
	}
	if (flag) ret1 = min(ret1, ret2);
	return memo[node][flag] = ret1;
}

int main() {
	memset(memo, -1, sizeof memo);
	int n, s, e, res,tmp,cnt=0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
		if (cnt ==0) {
			tmp = s;
			cnt++;
		}
	}
	res = solve(tmp, 0, 1);
	cout << res << endl;
	return 0;
}

/*
3
1 2
1 3

3
1 2
2 3

*/