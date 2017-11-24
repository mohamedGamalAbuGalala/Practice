#include "stdafx.h"
// E_Dist.cpp : Defines the entry point for the console application.
// By Bu_galala


#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

char A[2001], B[2001];
int memo[2001][2001], sA = 0, sB = 0;

int solve(int ind1, int ind2) {
	if (sA == ind1)
		return sB - ind2;
	if (sB == ind2)
		return sA - ind1;
	if (memo[ind1][ind2] != -1)
		return memo[ind1][ind2];
	if (A[ind1] == B[ind2])
		return solve(ind1 + 1, ind2 + 1);
	int  r[3];
	r[0] = 1 + solve(ind1 + 1, ind2);
	r[1] = 1 + solve(ind1, ind2 + 1);
	r[2] = 1 + solve(ind1 + 1, ind2 + 1);
	int m = r[0];
	for (int i = 1; i < 3; i++) {
		if (r[i] < m)
			m = r[i];
	}
	return memo[ind1][ind2] = m;
}

int main() {
	int  cnt = 0, T, res[11];
	memset(res, -1, sizeof res);
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(memo, -1, sizeof memo);
		bool Af = true, Bf = true;
		cin >> A;
		cin >> B;
		for (int i = 0; i < 2001 && cnt < 11 && (Af || Bf); i++) {
			if (A[i] == '\0' && Af) {
				sA = i;
				Af = false;
			}
			if (B[i] == '\0' && Bf) {
				sB = i;
				Bf = false;
			}
		}
		res[cnt++] = solve(0, 0);
	}
	for (int i = 0; i < cnt && cout << res[i] << endl; i++);

	return 0;
}

