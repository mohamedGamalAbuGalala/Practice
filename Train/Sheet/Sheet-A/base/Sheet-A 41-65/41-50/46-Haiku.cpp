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

char v[] = { 'a', 'e', 'i', 'o', 'u' };

bool check(string s, int n) {
	int cnt = 0, si = s.size();
	for (int i = 0; i < si; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (s[i] == v[j]) {
				cnt++;
				break;
			}
		}
	}
	return n == cnt;
}

int main() {
	string s1, s2, s3;
	getline(cin, s1);
	if (check(s1, 5)) {
		getline(cin, s2);
		if (check(s2, 7)) {
			getline(cin, s3);
			if (check(s3, 5)) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
