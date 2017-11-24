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
	int n, m, cnt, res = 0;
	cin >> n >> m;
	cnt = m;
	while (n > 0) {
		cnt--, n--, res++;
		if (cnt == 0)
			cnt = m, n++;
	}
	cout << res;
	return 0;
}
