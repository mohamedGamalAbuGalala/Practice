#include "stdafx.h"
// AIBOFOBIA.cpp : Defines the entry point for the console application.
// By Bu_galala


#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

char S[6001];
int memo[6001][6001], t, res[101], cnt = 0;

int solve(int s, int e) {
	if (s >= e)
		return 0;
	if (memo[s][e] != -1)
		return memo[s][e];
	if (S[s] == S[e])
		return solve(s + 1, e - 1);
	return memo[s][e] = min(1 + solve(s + 1, e), 1 + solve(s, e - 1));
}

int main() {
	memset(res, -1, sizeof res);
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(memo, -1, sizeof memo);
		cin >> S;
		for (int i = 0; i < 6001 && cnt < 6001; i++) {
			if (S[i] == '\0') {
				res[cnt] = solve(0, i - 1);
				cnt++;
				break;
			}
		}
	}
	for (int i = 0; i < cnt && cout << res[i] << endl; i++);

	return 0;
}

