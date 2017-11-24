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
#define frr(i,j, n) for(int i = j;i >= n;i--)
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int dp[11][111], a[11][111], n, m, T;

int slv(int idx, int rm) {
	if (idx == n)
		return 0;
	if (rm <= 0)
		return -999999999;
	int &ret = dp[idx][rm];
	if (ret == -1) {
		ret = -999999999;
		forr(i,0,rm)
			if (a[idx][i] >= 5)
				ret = max(ret, slv(idx + 1, rm - (i + 1)) + a[idx][i]);
	}
	return ret;
}
int main() { // dfil
	fl(); //TODO
	cin >> T;
	while (T-- and cin >> n >> m) {
		forr(i,0,n )
			forr(j, 0, m and cin>>a[i][j]);
		mem(dp, -1);
		double res = double(double(slv(0, m)) + double(1e-9)) / double(n);
		if (res < 5.0)
			printf("Peter, you shouldn't have played billiard that much.\n");
		else
			printf("Maximal possible average mark - %.2lf.\n", res);
	}
	return 0;
}
