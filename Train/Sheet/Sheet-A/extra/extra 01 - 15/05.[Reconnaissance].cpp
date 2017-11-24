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
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int n, a[1005], d, ans = 0;
	cin >> n >> d;
	forr(i, 0, n and cin>>a[i]);
	sort(a, a + n);
	forr(i,0,n)
		for (int j = 0; j < n; ++j)
			if (i != j and  max(a[i], a[j]) - min(a[i], a[j]) <= d)
				ans++;
	cout << ans;
	return 0;
}
