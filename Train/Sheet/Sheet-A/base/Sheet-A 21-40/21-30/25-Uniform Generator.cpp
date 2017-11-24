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
	int s, m;
	while (cin >> s >> m) {

		int res = __gcd(s,m);


/*
		int i, ar[100001];
		bool v[100001], good = 1;

		ar[0] = 0, v[0] = 1;

		for (i = 1; i < m; ++i) {
			ar[i] = (ar[i - 1] + s) % m;
			v[ar[i]] = 1;
		}
		for (int j = 0; j < m && good; ++j)
			if (v[j] == 0)
				good = 0;
*/


		cout << setw(10) << s << setw(10) << m << "    ";
		if (res != 1)
//		if (!good)
			cout << "Bad Choice" << endl << endl;
		else
			cout << "Good Choice" << endl << endl;
	}
	return 0;
}
