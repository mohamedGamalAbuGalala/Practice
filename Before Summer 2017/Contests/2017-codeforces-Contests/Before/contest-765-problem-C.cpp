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
	int k, a, b;
	cin >> k >> a >> b;
	int ans = a / k + b / k;
	if (a / k == 0 && b % k != 0)
		ans = -1;
	if (b / k == 0 && a % k != 0)
		ans = -1;
	cout << ans;
	return 0;
}
