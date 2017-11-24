#include "stdafx.h"
// KnapSack_1D.cpp : Defines the entry point for the console application.
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
>> 17
*/

int w[2001], v[2001], dp[2001];
int n, S;

int main(void) {
	memset(dp, -1, sizeof dp);
	cin >> n >> S;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	dp[0]= 0;
	for (int i = 0; i < n; i++) {
		for (int j = S; j > -1; j--) {
			if (dp[j] != -1 && j + w[i] <= S) {
				dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
			}
		}
	}
	int mx = 0;
	for (int i = 0; i <= S; i++) {
		mx = max(mx, dp[i]);
	}
	cout << mx << endl;
	return 0;
}