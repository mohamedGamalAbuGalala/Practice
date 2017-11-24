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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

using lli = long long int;
int dp[10005][105];
int N, K, a[10005];

int slv(int idx = 0, int sm = 0) {
	if (idx == N) {
		if (sm % K == 0)
			return 1;
		return 0;
	}
	int &ret = dp[idx][sm];
	if (ret == -1)
		ret = max(slv(idx + 1, (sm + a[idx]) % K),
				slv(idx + 1, (sm - a[idx]) % K));
	return ret;
}

int main() { // dfil
	fl(); //TODO
	int T;
	cin >> T;
	while (T--, cin >> N >> K) {
		mem(dp, -1);
		forr(i, 0, N and cin >> a[i]);
		if(slv())
			puts("Divisible");
		else
			puts("Not divisible");
	}
	return 0;
}
