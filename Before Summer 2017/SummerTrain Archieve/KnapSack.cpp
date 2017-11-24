// KnapSack.cpp : Defines the exported functions for the DLL application.
// by bu-galala
#include "stdafx.h"
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <typeinfo>
#include <vector>
#include <set>
using namespace std;

/*
4 4
1 8
2 4
3 0
2 5
2 3
>> 13
*/

int memo[2001][2001];
int w[2001], v[2001];
int n, S;

int solve(int ind, int cur) {
	if (ind == n) return 0;
	if (memo[ind][cur] != -1)return memo[ind][cur];
	int ret1 = 0, ret2 = 0;
	ret1 = solve(ind + 1, cur);
	if (cur + w[ind] <= S)
		ret2 = solve(ind + 1, cur + w[ind]) + v[ind];
	memo[ind][cur] = max(ret1, ret2);
	return memo[ind][cur];
}

int main(void) {
	do {
		cin >> S >> n;
		for (int i = 0; i < n; i++) {
			cin >> w[i] >> v[i];
		}
		memset(memo, -1, sizeof memo);
		int res = solve(0, 0);
		cout << res << endl;
	} while (S > 0 && n > 0);
	return 0;
}