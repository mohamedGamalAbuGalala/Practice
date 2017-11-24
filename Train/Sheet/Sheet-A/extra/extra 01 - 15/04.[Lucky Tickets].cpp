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
	int n, x, r[3] { 0 };
	cin >> n;
	forr(i,0,n and cin>>x)
		r[(x % 3)]++;
	cout << (r[0] / 2) + min(r[1], r[2]);
	return 0;
}
