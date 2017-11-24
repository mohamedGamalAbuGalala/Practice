#include "stdafx.h"
//// ELCS.cpp : Defines the entry point for the console application.
//// by bu_galala
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <string.h>
//using namespace std;
//
///*
//abcd
//adcd
//>>3
//*/
//
//string A, B;
//int dp[1001][1001];
//
//int main() {
//	int res = 0;
//	getline(cin, A);
//	getline(cin, B);
//	for (int i = 0; i < A.size(); i++) {
//		for (int j = 0; j < B.size(); j++) {
//			if (A[i] == B[j])
//				dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]);
//			dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
//			dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
//		}
//	}
//	res = dp[A.size()][0];
//	for (int i = 1; i <= B.size(); i++)
//		res = max(res, dp[A.size()][i]);
//	cout << res;
//	return 0;
//}
//
