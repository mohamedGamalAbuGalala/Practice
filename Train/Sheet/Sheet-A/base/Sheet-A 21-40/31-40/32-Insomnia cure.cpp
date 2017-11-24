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
	int k, l, m, n, d, cnt = 0, i;
	cin >> k >> l >> m >> n >> d;
	int ar[d+1];
	memset(ar, 0, sizeof ar);

	i = k;
	while (i <= d) {
		if (ar[i] == 0)
			cnt++, ar[i] = 1;
		i += k;
	}

	i = l;
	while (i <= d) {
		if (ar[i] == 0)
			cnt++, ar[i] = 1;
		i += l;
	}

	i = m;
	while (i <= d) {
		if (ar[i] == 0)
			cnt++, ar[i] = 1;
		i += m;
	}

	i = n;
	while (i <= d) {
		if (ar[i] == 0)
			cnt++, ar[i] = 1;
		i += n;
	}

	cout << cnt << endl;
	return 0;
}
