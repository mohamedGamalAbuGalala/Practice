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
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, k, l, r, x = 0;
	in(n), in(k);
	forr(i,0,n and in(l) and in(r))
		x += r - l + 1;
	cout << (k - ((x % k) ? (x % k) : k));
	return 0;
}
