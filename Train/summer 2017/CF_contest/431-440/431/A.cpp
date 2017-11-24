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

#define od(x) (x&1)? 1 : 0

int n, a[105];
bool ok = 0;

void slv(int l = 0, int r = 0, int sg = 0) {
	if (r == n) {
		if ((od((r - l))) and od(sg))
			ok = 1;
		return;
	}
	if (od((r+1-l)) and ((r + 1) < n) and od(a[(r + 1)]))
		slv(r + 1, r + 1, sg++);
	if (r + 1 < n and od(a[r + 1]) and r + 2 < n and od(a[r + 2]))
		slv(r + 2, r + 2, sg++);
}

int main() { // dfil
	fl(); //TODO

	cin >> n;
	forr(i, 0, n and cin>>(a[i]));
	if (!(a[0] & 1) or !(a[n - 1] & 1))
		return puts("No"), 0;
	if ((n & 1))
		return puts("Yes"), 0;
	return puts("No"), 0;
	ok = 0, slv();
	if (ok)
		return puts("Yes"), 0;
	return puts("No"), 0;
	return 0;
}
