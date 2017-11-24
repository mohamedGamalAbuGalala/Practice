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
#define sp() printf(" ")		//output single space
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int n, c[1005], l, r, s = 0, d = 0;
	bool trn = 1;
	in(n), l = 0, r = n - 1;
	forr(i, 0, n and in(c[i]));
	while (l <= r) {
		if (trn) {
			if (c[l] > c[r])
				s += c[l++];
			else
				s += c[r--];
		} else {
			if (c[l] > c[r])
				d += c[l++];
			else
				d += c[r--];
		}
		trn ^= 1;
	}
	ot(s), sp(), ot(d);
	return 0;
}
