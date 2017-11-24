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
#define mem(a,b) memset(a,b,sizeof(a))
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int t, n, ans, dp[1234][33], V[1234], W[1234], mw, g;

int slv(int idx = 0, int w = mw) {
	if (idx == n or !w)
		return 0;
	int &ret = dp[idx][w];
	if (ret == -1) {
		if (w < W[idx])
			ret = slv(idx + 1, w);
		else
			ret = max(slv(idx + 1, w), slv(idx + 1, w - W[idx]) + V[idx]);
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	in(t);
	while (t--) {
		in(n), ans = 0, mem(dp, -1);
		forr(i, 0, n and in((V[i])) and in((W[i])));
		in(g);
		forr(i,0,g and in(mw))
			ans += slv();
		ot(ans), ln();
	}
	return 0;
}
