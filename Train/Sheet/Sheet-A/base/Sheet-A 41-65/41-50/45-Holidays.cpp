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
	int n, mn, mx;
	cin >> n;
	int mod = n % 7, mul = n / 7;
	mn = mul * 2;

	if (mod == 1)
		mx = mn + 1;
	else if (mod >= 2)
		mx = mn + 2;
	else if (!mod)
		mx = mn;

	if (mod == 6)
			mn++;
	cout << mn << " " << mx;
	return 0;
}
