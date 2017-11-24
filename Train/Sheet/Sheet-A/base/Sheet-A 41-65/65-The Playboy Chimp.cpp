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
	int n, m;
	cin >> n;
	vector<unsigned int> ar;
	for (int i = 0; i < n; ++i) {
		unsigned int tmp;
		cin >> tmp;
		ar.pb(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		unsigned int tmp;
		cin >> tmp;
		int l, r;
		if (tmp > ar[n - 1]) {
			l = lower_bound(ar.begin(), ar.end(), ar[n - 1]) - begin(ar);
			r = -1;
			cout << ar[l] << " " << "X" << endl;
			continue;
		} else if (tmp == ar[n - 1]) {
			l = lower_bound(ar.begin(), ar.end(), ar[n - 1]) - begin(ar);
			r = -1;
			cout << ar[l - 1] << " " << "X" << endl;
			continue;
		} else if (tmp <= ar[0]) {
			l = -1;
			r = upper_bound(ar.begin(), ar.end(), tmp) - begin(ar);
			cout << "X" << " " << ar[r] << endl;
			continue;
		} else {
			l = lower_bound(ar.begin(), ar.end(), tmp) - begin(ar);
			r = upper_bound(ar.begin(), ar.end(), tmp) - begin(ar);
		}
		cout << ((ar[l] == tmp || l == r) ? ar[l - 1] : ar[l]) << " " << ar[r]
				<< endl;
	}
	return 0;
}
