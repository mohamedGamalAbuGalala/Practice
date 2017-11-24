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
	int n, m, i = 0;
	bool res = 1;
	cin >> n >> m;
	int points = n * m;
	while (points > 0) {
		if (n + i > 0)
			points -= (n + i);
		if (m + i > 0)
			points -= (m + i);
		points++, i--, res = !res;
	}
	if (res)
		cout << "Malvika";
	else
		cout << "Akshat";
	return 0;
}
