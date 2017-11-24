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
#define pp pair<int,int>

using namespace std;

int main() {
	int n, ons = 0, tws = 0, ths = 0;
	vector<pp> ar;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		pair<int, int> tmp;
		cin >> tmp.first;
		tmp.second = i + 1;
		ar.pb(tmp);
		if (tmp.first == 1)
			ons++;
		else if (tmp.first == 2)
			tws++;
		else
			ths++;
	}
	cout << min(ons, min(tws, ths)) << endl;

	sort(ar.begin(), ar.end());
	int _1 = 0;
	int _2 = ons ;
	int _3 = _2 + tws;

	while (ar[_1].first == 1 && ar[_2].first == 2 && ar[_3].first == 3)
		cout << ar[_1++].second << " " << ar[_2++].second << " "
				<< ar[_3++].second << endl;
	return 0;
}
