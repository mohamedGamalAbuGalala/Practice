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
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int x, y, z, n, xx, yy, zz;
int main() { // dfil
	fl(); //TODO
	cin >> n;
	forr(i,0,n and cin>> xx>>yy>>zz)
		x += xx, y += yy, z += zz;
	if ((!x and !y and !z))
		puts("YES");
	else
		puts("NO");
	return 0;
}
