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

using namespace std;

int main() {
	int s[26] = { 0 }, us[26] = { 0 };
	string g, h, n;
	cin >> g >> h >> n;
	for (int i = 0, si = g.size(); i < si; ++i) {
		int d = g[i] - 'A';
		s[d]++;
	}
	for (int i = 0, si = h.size(); i < si; ++i) {
		int d = h[i] - 'A';
		s[d]++;
	}
	for (int i = 0, si = n.size(); i < si; ++i) {
		int d = n[i] - 'A';
		us[d]++;
	}
	for (int i = 0; i < 26; ++i) {
		if (s[i] != us[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
