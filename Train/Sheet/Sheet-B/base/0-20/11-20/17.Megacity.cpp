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

int main() {
	file();
	int n, s, x1, y1, pop, idx = 0;
	vector<pair<double, int>> ar;
	scanf("%d%d", &n, &s);
	if (s >= (int) 1e6)
		return cout << 0, 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &x1, &y1, &pop);
		double distancex = x1 * x1, distancey = y1 * y1;
		double dist = sqrt(distancex + distancey);
		ar.pb(pair<double, int>(dist, pop));
	}
	sort(ar.begin(), ar.end());
	while (s < (int) 1e6 && idx < (int) ar.size())
		s += ar[idx++].second;
	if (idx == (int) ar.size() && s < (int) 1e6)
		return cout << -1, 0;
	printf("%.7lf", ar[idx - 1].first);
	return 0;
}
