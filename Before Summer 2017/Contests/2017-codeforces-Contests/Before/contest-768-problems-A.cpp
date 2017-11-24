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
	vector<ll> ar;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll tmp;
		cin >> tmp;
		ar.pb(tmp);
	}
	sort(ar.begin(), ar.end());
	int lind = lp(ar.begin(), ar.end(), ar[n - 1]) - ar.begin();
	int uind = up(ar.begin(), ar.end(), ar[0]) - ar.begin();
	if (lind - uind > 0)
		cout << lind - uind;
	else
		cout << 0;
	return 0;
}
