#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <array>
#include <iterator>
#include <set>
#include <stack>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	map<string, int> mp;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int tmp;
		string inp;
		cin >> inp >> tmp;
		mp[inp] = tmp;
	}
	for (int i = 0; i < m; ++i) {
		int res = 0;
		string inp;
		while (cin >> inp && inp != ".") {
			if (mp.find(inp) != mp.end())
				res += mp[inp];
		}
		cout << res << endl;
	}
	return 0;
}
