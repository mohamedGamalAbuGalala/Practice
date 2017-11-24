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
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int n, a, ar[101], res = 0, l, r;
	in(n), in(a), a--, l = a - 1, r = a + 1;
	forr(i, 0, n and in(ar[i]));
	if (ar[a])
		res++;
	while (l > -1 or r < n) {
		if (ar[l] and r >= n)
			res++;
		else if (ar[r] and l < 0)
			res++;
		else if (ar[l] and ar[r])
			res += 2;
		l--, r++;
	}
	ot(res);
	return 0;
}
