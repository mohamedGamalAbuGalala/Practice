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
	int n, res = 0;
	int p, bh = 0, ah = 0, gs = 0;
	in(n);
	forr(i, 0, n and in(p))
	{
		if (!p and ah)
			continue;
		else if (!p and !bh and gs and i < n - 1)
			bh = 1, res++;
		else if (!p and bh)
			res = max(0, res - 1), bh = 0, ah = 1;
		else if (p)
			res++, bh = 0, ah = 0, gs = 1;
	}
	ot(res);
	return 0;
}
