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

#define F first
#define S second
#define pb push_back
#define forr(i,j, n) for(int i = j;i < n;i++)
#define in(n) scanf("%d",&n)	//scan int
const int MN = 1e5 + 1e1;

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

pair<int, int> a[MN];

int main() { // dfil
	fl(); //TODO
	using lli = long long int;
	lli cmx = 0, mx = 0;
	int l = 0, r = 0, n, m;
	in(n), in(m);
	forr(i, 0, n and in(a[i].F) and in(a[i].S));
	sort(a, a + n);
	for (l = 0; l < n; mx = max(cmx, mx), cmx -= a[l].S, ++l)
		while (r < n and abs(a[l].F - a[r].F) < m)
			cmx += a[r].S, ++r;
	cout << mx;
	return 0;
}
