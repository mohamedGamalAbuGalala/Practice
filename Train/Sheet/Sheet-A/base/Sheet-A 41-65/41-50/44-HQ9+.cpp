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
	string s;
	cin >> s;
	for (int i = 0, si = s.size(); i < si; ++i)
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
			cout << "YES";
			return 0;
		}
	cout<<"NO";
	return 0;
}
