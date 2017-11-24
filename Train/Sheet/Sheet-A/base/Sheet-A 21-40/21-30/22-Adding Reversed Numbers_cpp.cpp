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

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;

void reverse(string & s) {
	for (int i = 0, n = s.size(), si = s.size() / 2; i < si; ++i) {
		char tmp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = tmp;
	}
}

string add(string a, string b) {
	string c;
	while (a.size() < b.size())
		a.insert(0, "0");
	while (b.size() < a.size())
		b.insert(0, "0");
	int carry = 0;
	bool flag = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		int n = a[i] - '0', m = b[i] - '0';
		n += (m + carry);
		if (n > 9) {
			carry = n / 10;
			n %= 10;
		} else
			carry = 0;
		if (n)
			flag = 1;
		if (flag)
			c += (n + '0');
	}
	if (carry)
		c += (carry + '0');
	return c;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string a, b, c;
		cin >> a >> b;
		reverse(a);
		reverse(b);
		c = add(a, b);
		cout << c << endl;
	}
	return 0;
}
