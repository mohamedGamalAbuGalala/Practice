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
#define otf(x) printf("%.12lf", x)// output double/float with 0.00
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int a[1009], n, l;
bool can(double x) {
	bool ok = 1;
	ok &= a[0] <= x;
	forr(i,1,n)
		ok &= (a[i] - a[i - 1]) <= 2 * x;
	ok &= (l - a[n - 1]) <= x;
	return ok;
}

double IBS() {
	double lo = 0.0, hi = l + 50, mid = 0.0, ans = 0.0;
	for (int i = 0; i < 50; i++) {
		mid = (lo + hi) / 2.0;
		if (can(mid))
			ans = mid, hi = mid;
		else
			lo = mid;
	}
	return ans;
}

int main() { // dfil
	fl(); //TODO
	in(n), in(l);
	forr(i, 0, n and in(a[i]));
	sort(a, a + n);
//	otf(IBS());
	double mxd = 0.0;
	mxd = max(a[0] * 1.0, mxd);
	forr(i,1,n)
		mxd = max((a[i] - a[i - 1]) / (2 * 1.0), mxd);
	mxd = max((l - a[n - 1]) * 1.0, mxd);
	otf(mxd);
	return 0;
}
