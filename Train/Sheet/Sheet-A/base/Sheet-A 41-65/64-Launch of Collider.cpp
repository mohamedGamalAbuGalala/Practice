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
#define ll long long int

using namespace std;

int main() {
	int n, ar[200001], l = 0, r = 0, lal = -1, fr = -1;
	string d;
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
		if (d[i] == 'L') {
			l++;
			lal = i;
		} else if (d[i] == 'R') {
			r++;
			if (fr == -1)
				fr = i;
		}
	}
	if (r == n || l == n || fr > lal) {
		cout << -1;
		return 0;
	}

	int res = 500000001;
	for (int i = 0; i < n - 1; ++i) {
		if (d[i] == 'R' && d[i + 1] == 'L')
			res = min(res, ((ar[i + 1] - ar[i]) / 2));
	}
	cout << res;

	/*
	 for (int i = 1; 1==1 ; ++i) {
	 for (int j = 0; j < n; ++j) {
	 if (d[j] == 'R')
	 ar[j]++;
	 else if (d[j] == 'L')
	 ar[j]--;
	 if (j > 0 && j < n - 1 && ar[j - 1] == ar[j]) {
	 cout << i;
	 return 0;
	 }
	 }
	 }
	 */

	return 0;
}
