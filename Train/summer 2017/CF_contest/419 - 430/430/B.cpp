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
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int r, rr, d, n, ans = 0, x, y, z;
	cin >> r >> d >> n;
	rr = r - d;
	forr(i,0,n and in(x) and in(y) and in(z)){
		double dis = sqrt(x * x + y * y);
		if (dis - z >= rr and dis + z <= r)
			ans++;
	}
	cout << ans;
	return 0;
}
