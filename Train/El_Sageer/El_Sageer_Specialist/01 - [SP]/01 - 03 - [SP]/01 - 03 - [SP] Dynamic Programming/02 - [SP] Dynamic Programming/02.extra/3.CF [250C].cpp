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
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int a[112345], x, n, k, s[112345], mx = -1, c, ls, nx;

int main() { // dfil
	fl(); //TODO
	in(n), in(k), in(a[0]);
	forr(i, 1, n and in(x))
		if (x == a[i - 1])
			i--, n--;
		else
			a[i] = x;
	s[a[0]]++, s[a[n - 1]]++, mx = max(mx, s[a[0]]);
	forr(i,1,n-1)
		ls = a[i - 1], c = a[i], nx = a[i + 1], s[c] += 1 + (ls == nx), mx =
				max(mx, s[c]);
	forr(i,1,k+1)
		if (s[i] == mx)
			return cout << i, 0;
	return 0;
}
