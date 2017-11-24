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
	int n, mx = 0, mn = INT16_MAX;
	cin >> n;
	int ar[n];
	cin >> ar[0];
	for (int i = 1; i < n; ++i) {
		cin >> ar[i];
		mx = max(mx, ar[i] - ar[i - 1]);
	}

	for (int i = 1; i < n - 1; ++i) {
		int dif = ar[i + 1] - ar[i - 1];
		if (mx > dif)
			dif = mx;
		mn = min(mn, dif);
	}
	cout << mn;
	return 0;
}
