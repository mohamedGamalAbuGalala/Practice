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
	int n;
	string inp;
	int v[26], pangram = 1;
	memset(v, 0, sizeof v);
	cin >> n;
	cin >> inp;
	if (n < 26) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0, s = inp.size(); i < s; ++i) {
		if (isupper(inp[i]))
			inp[i] = tolower(inp[i]);
		int ind = inp[i] - 'a';
		v[ind]++;
	}
	for (int i = 0; i < 26 && pangram; ++i)
		if (v[i] == 0)
			pangram = 0;
	if (pangram == 1)
		cout << "YES" << endl;
	else if (pangram == 0)
		cout << "NO" << endl;
	return 0;
}
