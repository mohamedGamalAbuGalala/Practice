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
	int n, m, c;
	while (cin >> n >> m >> c) {
		if (n + m + c == 0)
			break;
		if (c == 0)
			cout << ((n - 7) * (m - 7) / 2) << endl;
		else
			cout << (((n - 7) * (m - 7) + 1) / 2) << endl;
	}
	return 0;
}
