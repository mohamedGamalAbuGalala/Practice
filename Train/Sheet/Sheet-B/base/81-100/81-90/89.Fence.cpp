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
const int OO = 1e9 + 5;

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, k, h[200000] { 0 }, mn = OO, mid = -1;
	in(n), in(k);
	forr(i, 1, n+1 and in(h[i]))
	{
		h[i] += h[i - 1];
		if (i - k >= 0) {
			int df = h[i] - h[i - k];
			if (df < mn)
				mn = df, mid = i - k + 1;
		}
	}
	ot(mid);
	return 0;
}
