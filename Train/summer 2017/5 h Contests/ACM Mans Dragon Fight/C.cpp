//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

#define INF 1e18
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 1e3 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int dp[4][N][N], a[N][N];

int main() {
	file();

	int n, m, ans = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m && cin >> a[i][j]; j++)
			;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[0][i][j] = a[i][j], dp[0][i][j] += max(dp[0][i][j - 1],
					dp[0][i - 1][j]);

	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			dp[2][i][j] = a[i][j], dp[2][i][j] += max(dp[2][i + 1][j],
					dp[2][i][j - 1]);

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			dp[3][i][j] = a[i][j], dp[3][i][j] += max(dp[3][i - 1][j],
					dp[3][i][j + 1]);

	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			dp[1][i][j] = a[i][j], dp[1][i][j] += max(dp[1][i + 1][j],
					dp[1][i][j + 1]);

	for (int i = 2; i < n; i++)
		for (int j = 2; j < m; j++)
			ans = max(
					dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1]
							+ dp[3][i][j + 1], ans), ans = max(
					dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j]
							+ dp[3][i - 1][j], ans);

	cout << ans;

	return 0;
}
