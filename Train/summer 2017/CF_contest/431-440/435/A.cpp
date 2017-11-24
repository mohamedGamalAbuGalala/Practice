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
#define forr(i,j, n) for(int i = j;i < n;i++)

int main() { // dfil
	fl(); //TODO
	int n, x, a[111], ans = 0;
	cin >> n >> x;
	forr(i, 0, n and cin>>(a[i]));
	sort(a, a + n);
	int ii = 0;
	forr(i,0,x)
		if (a[ii] != i)
			ans++;
		else
			ii++;
	if (a[ii] == x)
		ans++;
	cout << ans;
	return 0;
}
