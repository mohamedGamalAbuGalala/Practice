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
#define pr pair<int,int>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string inp[n];
	for (int i = 0; i < n; ++i) {
		cin >> inp[i];
		string cur = inp[i];
		for (int j = 1; j < m; ++j) {
			if (cur[j] != cur[0]) {
				cout << "NO";
				return 0;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		int d1 = inp[i][0] - '0';
		int d2 = inp[i + 1][0] - '0';
		if (d1 == d2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
