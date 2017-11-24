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
	string inp, ar[10], cur;
	cin >> inp;
	for (int i = 0; i < 10 && cin >> ar[i]; ++i)
		;
	for (int i = 0, si = inp.size(); i < si; ++i) {
		cur += inp[i];
		if (cur.size() == 10) {
			for (int j = 0; j < 10; ++j) {
				if (cur == ar[j]) {
					cout << j;
					break;
				}
			}
			cur = "";
		}
	}
	return 0;
}
