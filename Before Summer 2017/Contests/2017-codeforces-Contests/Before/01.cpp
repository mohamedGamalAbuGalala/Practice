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

/*
string a, b;

int mn, mx;

bool check(int l) {
	for (int i = 0; i + l < mn; ++i)
		for (int j = 0; j < l; ++j)
			if (a[j] == b[j])
				return 0;
	return 1;
}
*/


int main() {
	string a, b;
	int mn , mx;
	cin >> a >> b;
	mn = (a.size() < b.size()) ? a.size() : b.size();
	mx = (a.size() > b.size()) ? a.size() : b.size();

	int m = 0 , cnt = 0;
	for (int i = 0; i < mn; ++i) {
		if(a[i] == b[i]){
			m = max(m,cnt);
			cnt = 0;
			continue;
		}
		cnt++;
		m = max(m,cnt);
	}
	if(m == mn)
		m = mx;

	if(m == 0) cout<<"-1"<<endl;
	else cout<<m<<endl;

	/*int s = 0, e = mx, mid = 0;
	while (s < e) {
		mid = s + e / 2;
		if (check(mid))
			s = mid + 1;
		else
			e = mid - 1;
	}
	if (mid == 0)
		cout << "-1";
	else
		cout << mid;

		*/
	return 0;
}
