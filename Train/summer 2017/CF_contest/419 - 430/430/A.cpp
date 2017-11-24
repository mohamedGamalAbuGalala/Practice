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
using lli = long long int;
#define forr(i,j, n) for(lli i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	lli l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	forr(i,x,y+1)
		if (l <= i * k and i * k <= r)
			return puts("Yes"), 0;
	puts("No");
	return 0;
}
