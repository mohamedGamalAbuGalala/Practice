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
lli dp[301][301][301];
int num[3], N;
lli slv(int n, int val, int cnt) {
	if (!n and !cnt)
		return 1;
	if (val > N or n < 0 or !cnt)
		return 0;
	lli &ret = dp[n][val][cnt];
	if (ret == -1)
		ret = slv(n - val, val, cnt - 1) + slv(n, val + 1, cnt);
	return ret;
}

int main() { // dfil
	fl(); //TODO
	string str;
	mem(dp, -1);
	while (getline(cin, str)) {
		stringstream sin(str);
		mem(num,0), N = 0;
		while (sin >> num[N])
			N++;
		int p, q;
		if (N == 1)
			p = 0, q = num[0];
		else if (N == 2)
			p = 0, q = num[1];
		else
			p = num[1], q = num[2];
		N = num[0], q = min(N, q);
		lli ans = 0;
		forr(i,p,q+1)
			ans += slv(N, 1, i);
		printf("%lld\n", ans);
	}
	return 0;
}
