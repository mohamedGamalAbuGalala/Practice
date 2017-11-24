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
#define mem(a,b) memset(a,b,sizeof(a))
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)

int n, dp[111][5], a[111];

int solve(int i = 0, int p = 0) {
	if (i == n)
		return 0;
	int &ret = dp[i][p];
	if (ret != -1)
		return ret;
	ret = solve(i + 1, 0);		// skip the current ( take a rest... )
	if (a[i] == 1 and p != 1)
		ret = max(ret, solve(i + 1, 1) + 1);	// consider p = 1 as contest day
	if (a[i] == 2 and p != 2)
		ret = max(ret, solve(i + 1, 2) + 1);	// consider p = 2 as gym day
	if (a[i] == 3) {
		if (p != 1)
			ret = max(ret, solve(i + 1, 1) + 1);// consider p = 1 as contest day
		if (p != 2)
			ret = max(ret, solve(i + 1, 2) + 1);	// consider p = 2 as gym day
	}
	return ret;		// maximize all possibilities and return...
}

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	mem(dp,-1), in(n);
	forr(i, 0, n and in(a[i]));
	ot(n - solve());
	return 0;
}
