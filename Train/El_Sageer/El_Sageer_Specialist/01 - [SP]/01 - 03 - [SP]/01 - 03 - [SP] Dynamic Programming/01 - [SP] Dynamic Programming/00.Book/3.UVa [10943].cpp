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
#define forr(i,j, n) for(int i = j;i < n;i++)
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int N, K, dp[111][111];

int ways(int n, int k) {
	if (k == 1)
		return 1;
	int &ret = dp[n][k];
	if (ret == -1) {
		ret = 0;
		forr(i,0,n+1)
			ret += ways(n - i, k - 1) % 1000000;
	}
	return ret % 1000000;
}

int main() { // dfil
	fl(); //TODO
	//	mem(dp, -1);
//	while (in(N) and in(K) and N and K)
//		ot(ways(N,K)), ln();
	mem(dp, 0), dp[0][0] = 1;
	forr(kk,0,101)
		forr(nn,0,101)
			forr(pls,0,((100-nn)+1))
				dp[nn + pls][kk + 1] += dp[nn][kk], dp[nn + pls][kk + 1] %=
						1000000;
	while (in(N) and in(K) and N and K)
		ot(dp[N][K]), ln();
	return 0;
}
