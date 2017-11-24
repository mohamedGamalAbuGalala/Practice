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
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ff first
#define ss second
#define pb push_back
typedef pair<int, int> ii;
#define all(v) v.begin(), v.end()
typedef vector<ii> vii;
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int n, x, m = 1, l, r, ans = 0, cur = 0;
	vii g;
	in(n), in(x);
	forr(i, 0, n and in(l) and in(r))
		g.pb( { l, r });
	sort(all(g));
	while (m <= g[sz(g) - 1].ss) {
		if (m + x <= g[cur].ff)
			m += x;
		else
			ans += g[cur].ss - m + 1, m = g[cur++].ss + 1;
	}
	ot(ans);
	return 0;
}
