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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, v;
	x = min(b * c, a * d), y = max(b * c, a * d);
	x = y - x, v = __gcd(x, y);
	cout << x / v << "/" << y / v;
	return 0;
}
