//#include "stdafx.h"
//// ELCS.cpp : Defines the entry point for the console application.
//// by bu_galala

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

/*
abcd
adcd
>>3
*/

string A, B;
int memo[1001][1001];

int solveR(int i, int j) {
	if (i == A.size() || j == B.size()) return 0;
	if (memo[i][j] != 0) return memo[i][j];
	int ret1 = 0, ret2 = 0;
	if (A[i] == B[j])
		ret1 = 1 + solveR(i + 1, j + 1);
	ret2 = max(solveR(i + 1, j), solveR(i, j + 1));
	return memo[i][j] = max(ret1, ret2);
}

int main() {
	int res = 0;
	getline(cin, A);
	getline(cin, B);
	res = solveR(0, 0);
	cout << res;
	return 0;
}

