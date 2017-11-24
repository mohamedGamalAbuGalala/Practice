#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, l, r;
	string a, b;
	cin >> n >> a, b = a;
	if (n & 1)
		l = r = (n / 2);
	else
		l = r = ((n - 2) / 2), r++;
	bool fl = 1;
	for (auto ch : a) {
		if ((n & 1) and l == r)
			b[l] = ch, l--, r++;
		else if (fl)
			b[l] = ch, fl ^= 1, l--;
		else if (!fl)
			b[r] = ch, fl ^= 1, r++;
	}
	cout << b;
	return 0;
}
