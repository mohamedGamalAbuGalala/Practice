#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;

string A, B;
int memo[1001][1001];
int mx , mn;

int solveR(int i, int j) {
	if (i == A.size() || j == B.size())
		return mx - mn;
	if (memo[i][j] != 0)
		return memo[i][j];
	int ret1 = 0, ret2 = 0;
	if (A[i] != B[j])
		ret1 = 1 + solveR(i + 1, j + 1);
	ret2 = max(solveR(i + 1, j), solveR(i, j + 1));
	return memo[i][j] = max(ret1, ret2);
}

int main() {
	int res = 0;
	getline(cin, A);
	getline(cin, B);
	 mn = min(A.size(), B.size());
	 mx = max(A.size(), B.size());
	res = solveR(0, 0);
	if (!res)
		cout << "-1" << endl;
	else
		cout << res << endl;
	return 0;
}

