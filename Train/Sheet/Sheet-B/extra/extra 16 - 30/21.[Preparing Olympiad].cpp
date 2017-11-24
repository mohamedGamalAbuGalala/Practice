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
#define isOn(S, j) (S & (1 << j))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, l, r, x, a[16];
	cin >> n >> l >> r >> x;
	forr(i, 0, n and cin>>(a[i]));
	int ans = 0;
	forr(i,0,(1<<n))
	{
		int mx = 0, mn = 999999999, tot = 0;
		forr(j,0,n)
			if (isOn(i, j))
				mn = min(mn, a[j]), mx = max(mx, a[j]), tot += a[j];
		if (tot >= l and tot <= r and abs(mx - mn) >= x)
			ans++;
	}
	cout << ans;
	return 0;
}
