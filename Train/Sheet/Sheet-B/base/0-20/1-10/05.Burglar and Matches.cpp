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

const lli N = 2e8 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);



int main() {
	file();
	pair<lli,lli> ar[21];
	lli res = 0, n, m, i;
	cin >> n >> m;
	for (i = 0; i < m && cin >> ar[i].second >> ar[i].first; ++i)
		;
	sort(ar, ar + m);
	i = m-1;
	while (i > -1 && n )
		if (ar[i].second <= n)
			res += ar[i].first * ar[i].second, n -= ar[i].second, i--;
		else
			res += n * ar[i].first, n = 0;
	return cout << res, 0;
}
