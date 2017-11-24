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
	int n, k, ar[210];
	cin >> n >> k;
	for (int i = 0; i < (2 * n + 1) && cin >> ar[i]; ++i)
		;
	for (int i = 1; i < 2 * n && k > 0; ++i)
		if ((ar[i] - 1 > ar[i - 1]) && (ar[i] - 1 > ar[i + 1]))
			ar[i]--, k--;
	for (int i = 0; i < (2 * n + 1) && cout << ar[i] << " "; ++i)
		;
	return 0;
}
