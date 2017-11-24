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
#define mem(a,b) memset(a,b,sizeof(a))
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;
lli dp[301][301];

int main() { // dfil
	fl(); //TODO
	string str;
	dp[0][0] = 1;
	forr(i,1,301)
		forr(j,i,301)
			forr(k,1,j+1)
				dp[j][k] += dp[j - i][k - 1];
	while (getline(cin, str)) {
		stringstream sin(str);
		int num[3] { 0 }, n = 0;
		while (sin >> num[n])
			n++;
		int p, q;
		if (n == 1)
			p = 0, q = num[0];
		else if (n == 2)
			p = 0, q = num[1];
		else
			p = num[1], q = num[2];
		n = num[0], q = min(n, q);
		lli ans = 0;
		forr(i,p,q+1)
			ans += dp[n][i];
		printf("%lld\n", ans);
	}
	return 0;
}
