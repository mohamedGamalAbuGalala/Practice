#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//	freopen("ot.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);	// HERE
	freopen("output.txt", "w", stdout);
#endif
}
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int n, a[int(1e5 + 100)] , ans = 11111111;

int main() { // dfil
	fl(); //TODO
	in(n);
	forr(i, 0, n and in(a[i]));
	sort(a, a + n);
	forr(i,0,n) /// removed from left = i + removed from right = n - upp(2*a[i])
		ans = min(ans, i + n - (int) (upper_bound(a, a + n, 2 * a[i]) - a));
	ot(ans);
	return 0;
}
