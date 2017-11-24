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

	int n, s, d;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;

	cin >> s >> d;

	if(s>d)
		swap(s,d);

	int r1 = 0, r2 = 0, st = s, dt = d;

	while (st < d) {
		r1 += ar[st - 1];
		st++;
	}

	while (dt != s) {
		if (dt > n){
			dt = 1;
			continue;
		}
		r2 += ar[dt - 1];
		dt++;
	}

	cout << min(r1, r2) << endl;
	return 0;
}
