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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int a[11][111], n, m, T;
	cin >> T;
	while (T-- and cin >> n >> m) {
		forr(i,1,n +1)
			forr(j, 1, m+1 and cin>>a[i][j]);
		int dp[11][111] { 0 };
		forr(i,1,m+1)
			if (a[1][i] >= 5)
				dp[1][i] = a[1][i];
		forr(i,2,n+1)
			forr(j,1,m+1)
			{
				int mx = 0;
				forr(k,1,j)
					if (a[i][k] >= 5 and dp[i - 1][j - k])
						mx = max(mx, a[i][k] + dp[i - 1][j - k]);
				dp[i][j] = mx;
			}
		double res = ((dp[n][m] * 1.0) + 1e-9) / (n * 1.0);
		if (!int(res))
			cout << "Peter, you shouldn't have played billiard that much.\n";
		else
			printf("Maximal possible average mark - %.2lf.\n", res);
	}
	return 0;
}
