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


int main() { // dfil
	fl(); //TODO
	int t, n, ans, dp[33], v, w, mw, g;
	in(t);
	while (t--) {
		in(n), ans = 0, mem(dp, 0);
		forr(i,0,n and in(v) and in(w))
			frr(j,30,w)
				dp[j] = max(dp[j], dp[j - w] + v);
		in(g);
		forr(i,0,g and in(mw))
			ans += dp[mw];
		ot(ans), ln();
	}
	return 0;
}
