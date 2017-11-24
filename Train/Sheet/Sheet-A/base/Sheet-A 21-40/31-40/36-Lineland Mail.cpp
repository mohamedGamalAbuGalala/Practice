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
	int n;
	cin >> n;
	ll ar[n];
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	sort(ar, ar + n);
	ll mx = ar[n - 1], mn = ar[0];
	for (int i = 0; i < n; ++i) {
		ll l = (i != 0) ? ar[i - 1] : -(INT64_MAX);
		ll r = (i != n - 1) ? ar[i + 1] : INT64_MAX;
		if (i == 0)
			cout << (r - ar[i]) << " " << max(mx - ar[i], ar[i] - mn) << endl;
		else if (i == n - 1)
			cout << (ar[i] - l) << " " << max(mx - ar[i], ar[i] - mn) << endl;
		else
			cout << min((ar[i] - l), (r - ar[i])) << " "
					<< max(mx - ar[i], ar[i] - mn) << endl;
	}
	return 0;
}
