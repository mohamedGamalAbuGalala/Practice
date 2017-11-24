#include "stdafx.h"
// KnapSack.cpp : Defines the entry point for the console application.
// by bu_galala
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

/*
4 5
1 8
2 4
3 0
2 5
2 3
>> 13
*/

int w[2001], v[2001], dp[2001][2001];
int n, S;

int main(void) {
	memset(dp, -1, sizeof dp);
	cin >> n >> S;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= S; j++) {
			if (dp[i][j] != -1) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				if (j + w[i] <= S)
					dp[i + 1][j + w[i]] = dp[i][j] + v[i];
			}
		}
	}
	int mx = 0;
	for (int i = 0; i <= S; i++) {
		mx = max(mx, dp[n][i]);
	}
	cout << mx << endl;
	return 0;
}