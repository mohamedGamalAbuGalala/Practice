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

const lli N = 300;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

vi g[N];
int vs[N];

void dfs(int x) {
	vs[x] = 1;
	for (int i = 0; i < (int) g[x].size(); i++) {
		int to = g[x][i];
		if (vs[to] == 0)
			dfs(to);
	}
}

int main() {
	file();
	int n, m, ans = 0, nn, l, z = 0;
	vi lang[N];

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nn;
		z = (nn) ? z : z + 1;
		for (int j = 0; j < nn; j++) {
			cin >> l;
			l--;
			lang[l].push_back(i);
		}
	}

	if (z == n)
		return cout << n * 100, 0;

	for (int i = 0; i < m; i++)
		for (int j = 1; j < (int) lang[i].size(); j++)
			g[lang[i][j]].push_back(lang[i][j - 1]), g[lang[i][j - 1]].push_back(
					lang[i][j]);

	for (int i = 0; i < n; i++)
		if (vs[i] == 0)
			ans++, dfs(i);

	cout << (ans - 1) * 100;
	return 0;
}
