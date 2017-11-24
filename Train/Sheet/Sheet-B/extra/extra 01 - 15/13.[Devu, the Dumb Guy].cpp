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
	using lli = long long int;
	lli ans = 0;
	int n, lp, a[111111];
	in(n), in(lp);
	forr(i, 0, n and in(a[i]));
	sort(a, a + n);
	forr(i,0,n)
		ans += lli(lli(a[i]) * lli(lp)), lp = max(lp - 1, 1);
	cout << ans;
	return 0;
}
