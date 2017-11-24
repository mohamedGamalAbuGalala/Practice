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
	int n, k, res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		string inp;
		int v[10] = { 0 };
		bool good = 1;
		cin >> inp;
		for (int j = 0, si = inp.size(); j < si; ++j) {
			int d = inp[j] - '0';
			v[d]++;
		}
		for (int j = 0; j <= k; ++j) {
			if (v[j] == 0) {
				good = 0;
				break;
			}
		}
		if (good)
			res++;
	}
	cout << res;
	return 0;
}
