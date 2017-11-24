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
	lli n, k, t;
	cin >> n >> k >> t;
	if (t < k)
		cout << t;
	else if (k <= t and t <= n)
		cout << k;
	else if (t > n)
		cout << (((k - (t - n)) < 0) ? 0 : k - (t - n));
	return 0;
}
