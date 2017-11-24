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
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int dp[11][112][112], T, k, m;

int slv(int kLeft, int low, int hi) {
	if (low == hi)
		return 0;
	if (!kLeft)
		return 912345678;
	int &ret = dp[kLeft][low][hi];
	if (ret == -1) {
		ret = 912345678;
		forr(i,low+1,hi+1)
			ret = min(ret,
					i + max(slv(kLeft - 1, low, i - 1), slv(kLeft, i, hi)));
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	in(T), mem(dp, -1);
	while (T-- and in(k) and in(m))
		ot(slv(k,0,m)), ln();
	return 0;
}
