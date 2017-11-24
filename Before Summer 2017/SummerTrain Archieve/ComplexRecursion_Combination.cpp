//============================================================================
// Name        : ComplexRecursion.cpp
// Author      : glala
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
int n;

void solve(char arr[], string cur, int ind) {

	if (ind == n)
		cout << cur << endl;
	else {
		solve(arr, cur + arr[ind], ind + 1);
		if (ind + 1 < n) {
			swap(arr[ind], arr[ind + 1]);
			solve(arr, cur + arr[ind], ind + 1);
		}
	}
}

int main() {
	cin >> n;

	char arr[n];

	for (int i = 0; i < n && cin >> arr[i]; ++i)
		;
	solve(arr, "", 0);
	return 0;
}

