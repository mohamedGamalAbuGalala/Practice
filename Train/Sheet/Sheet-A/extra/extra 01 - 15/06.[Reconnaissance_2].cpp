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
	int n, a[105], best = 0;
	cin >> n;
	forr(i, 0, n and cin>>a[i]);
	forr(i,0,n)
		if (abs(a[i] - a[(i + 1) % n]) < abs(a[best] - a[(best + 1) % n]))
			best = i;
	cout << best + 1 << " " << (best + 1) % n + 1;
	return 0;
}
