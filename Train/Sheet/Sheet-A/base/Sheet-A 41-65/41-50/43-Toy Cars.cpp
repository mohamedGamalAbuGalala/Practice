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
	int n, inp;
	vector<int> res;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		bool row = 1;
		for (int j = 0; j < n; ++j) {
			cin >> inp;
			if (inp == 1 || inp == 3)
				row = 0;
		}
		if (row)
			res.pb(i + 1);
	}
	cout << res.size() << endl;
	for (int i = 0, si = res.size(); i < si && cout << res[i] << " "; ++i)
		;
	return 0;
}
