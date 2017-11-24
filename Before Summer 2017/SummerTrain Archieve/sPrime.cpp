// sPrime.cpp : Defines the entry point for the console application.
// by bu-galala
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

/*
n <= 8
*/
int n;
int d[] = { 1, 2, 3, 5, 7, 9 };
bool isPrime(int n) {
	if (n == 0 && n == 1) return 0;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return 0;
	}
	return 1;
}
void solve(int num, int dig) {
	if (dig == n) {
		cout << num << endl;
		return;
	}
	for (int i = 0; i < 6; i++) {
		if (isPrime((num * 10) + d[i]))
			solve((num * 10) + d[i], dig + 1);
	}

}

int main() {
	do {
		cin >> n;
		solve(0, 0);
	} while (n>0);
	return 0;
}

