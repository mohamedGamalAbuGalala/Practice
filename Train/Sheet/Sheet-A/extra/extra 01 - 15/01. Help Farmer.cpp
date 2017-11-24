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
	using lli = long long int;
	const lli OO = 1e18 + 1e5;
	lli n;
	lli a, b, c, mn = OO;
	cin >> (n);
	for (a = 1; a * a * a <= n; ++a)
		if (n % a == 0)
			for (b = a; b * b <= n / a; ++b)
				if ((n / a) % b == 0)
					c = n / (a * b), mn = min(mn,
							(a + 1) * (b + 2) * (c + 2) - a * b * c);
	cout << mn << " " << n * 8 + 9;
	return 0;
}
