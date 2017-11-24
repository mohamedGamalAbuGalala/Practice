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
	unsigned long long int l, r, a, b, c, i, j, k;
	cin >> l >> r;
	if (r - l < 2) {
		cout << -1;
		return 0;
	}
	for (i = l; i <= r - 2; ++i) {
		a = i;
		for (j = a + 1; j <= r - 1; ++j) {
			b = j;
			if (__gcd(a, b) != 1)
				continue;
			for (k = b + 1; k <= r; ++k) {
				c = k;
				if ((__gcd(b, c) == 1) && __gcd(a, c) != 1) {
					cout << a << " " << b << " " << c;
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}
