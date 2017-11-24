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
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int k, mx = 0, x;
	in(k);
	forr(i,0,k and in(x))
		mx = max(mx, x);
	if (mx > 25)
		cout << mx - 25;
	else
		cout << 0;
	return 0;
}
