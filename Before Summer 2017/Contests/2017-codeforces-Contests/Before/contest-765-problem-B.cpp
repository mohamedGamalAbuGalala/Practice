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
#include <map>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	string inp;
	cin >> inp;
	int ar[26] = { 0 }, si = inp.size();
	for (int i = 0; i < si; ++i) {
		int ind = inp[i] - 'a';
		for (int j = ind - 1; j >= 0 && ind != 0; --j) {
			if (ar[j] == 0) {
				cout<<"NO";
				return 0;
			}
		}
		ar[ind] = 1;
	}
	cout<<"YES";
	return 0;
}
