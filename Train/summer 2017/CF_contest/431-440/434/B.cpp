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
#define F first
#define S second
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int n, m, l = 1, r, a, f;

int main() { // dfil
	fl(); //TODO
	cin >> n >> m;
	r = INT_MAX;
	for (int i = 0; i < m; ++i) {
		cin >> a >> f;
		l = max(l, 1 + (a - 1) / f);
		if (f > 1)
			r = min(r, (a - 1) / (f - 1));
	}
	l = 1 + (n - 1) / l;
	r = 1 + (n - 1) / r;
	cout << (l == r ? l : -1);
	return 0;
}
