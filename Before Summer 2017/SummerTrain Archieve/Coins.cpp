// Coins.cpp : Defines the entry point for the console application.
// by :: bu_glala
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
long long int n, res = 0;
int memo[1000001];

long long int solve(long long int n) {
	if (n == 0) return 0;
	if (n <= 1e6) {   //  1e6  == 1000000
		if (memo[n] != -1)
			return memo[n];
		return memo[n] = max(n, (solve(n / 2) + solve(n / 3) + solve(n / 4)));
	}
	return max(n, (solve(n / 2) + solve(n / 3) + solve(n / 4)));
}

int main(void)
{
	memset(memo, -1, sizeof memo);
	cin >> n;
	res =  solve(n);
	cout << res;
	return 0;
}