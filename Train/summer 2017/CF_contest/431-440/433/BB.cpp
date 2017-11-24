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
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	using lli = long long int;
	lli n, k;
	cin >> n >> k;
	int mn, mx;
	if (n == k)
		mn = mx = 0;
	else {
		if (k)
			mn = 1;
		else
			mn = 0;
		mx = min(n - k, k * 2);
	}
	cout << mn << " " << mx;
	return 0;
}
