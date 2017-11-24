// Greatest Seq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int A[2001], memo[2001], n;
int B[2001], memoB[2001][2001];
/*
7
1 3 2 5 4 8 3
>>4
*/

int solve_2_i(int cur, int Previ) {
	if (cur == n + 1) return 0;
	if (memoB[cur][Previ] != 0)
		return memoB[cur][Previ];
	int ret1 = 0 ,ret2 = 0;
	if (B[cur] > B[Previ])
		ret1 = max(ret1, 1 + solve_2_i(cur + 1, cur));
	ret2 = max(ret2,solve_2_i(cur + 1, Previ));
	return memoB[cur][Previ] = max(ret1,ret2);
}

int solve_i(int ind) {
	if (memo[ind] != 0)
		return memo[ind];
	int ret = 0;
	for (int i = ind + 1; i <= n; i++) {
		if (A[ind] < A[i])
			ret = max(ret, 1 + solve_i(i));
	}
	return memo[ind] = ret;
}

int main() {
	cin >> n;
	A[0] = -1;
	B[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		B[i] = A[i];
	}
	//int res = solve_i(0);
	int res = solve_2_i(1,0);
	cout << res;
	return 0;
}

