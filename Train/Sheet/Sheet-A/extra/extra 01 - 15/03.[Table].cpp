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
	int n, m, x;
	cin >> n >> m;
	bool isTwo = 0;
	forr(i,0,n)
		forr(j,0,m and cin>>x)
			if (x) {
				if (!i or i == (n - 1))
					isTwo = 1;
				if (!j || j == (m - 1))
					isTwo = 1;
			}
	if (isTwo)
		cout << 2;
	else
		cout << 4;
	return 0;
}
