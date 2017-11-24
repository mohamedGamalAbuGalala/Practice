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
	int q, d, l, data = 0, wait = 0;
	cin >> q >> d >> l;
	for (int t = 1; t <= l; ++t) {
		data += d - q;
		while (data < 0)
			data += d, ++wait;
	}
	cout << wait;
	return 0;
}
