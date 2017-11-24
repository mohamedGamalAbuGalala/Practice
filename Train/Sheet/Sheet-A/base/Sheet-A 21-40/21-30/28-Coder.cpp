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
int main() {
	int n , res = 0;
	cin >> n;
	int ar[n][n];
	char ot[n][n];
	memset(ar, 0, sizeof ar);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (ar[i][j] == 0) {
				ar[i][j] = 1, ot[i][j] = 'C';

				res++;

				if (i + 1 < n && (ar[i + 1][j] != 1))
					ar[i + 1][j] = -1, ot[i + 1][j] = '.';
				if (i - 1 > -1 && (ar[i - 1][j] != 1))
					ar[i - 1][j] = -1, ot[i - 1][j] = '.';
				if (j + 1 < n && (ar[i][j + 1] != 1))
					ar[i][j + 1] = -1, ot[i][j + 1] = '.';
				if (j - 1 > -1 && (ar[i][j - 1] != 1))
					ar[i][j - 1] = -1, ot[i][j - 1] = '.';
			}
		}
	cout<<res<<endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << ot[i][j];
		cout << endl;
	}
	return 0;
}
