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
	ll n, m, res = 0, rem[] = { 0, 0, 0, 0, 0 };
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		rem[i % 5]++;

	for (int i = 1; i <= m; ++i)
		res += rem[(5 - (i % 5)) % 5];

	/*	unsigned ll n, m, res = 0;
	 cin >> n >> m;
	 for (unsigned ll i = 1; i <= n; ++i) {
	 unsigned ll s = 5 - (i % 5);
	 for (unsigned ll j = s; j <= m; j += 5)
	 res++;
	 }
	 */
	cout << res;
	return 0;
}
