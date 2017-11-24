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

const lli N = 1e3 + 9;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int n;
lli dis[N][N];
vii adj[N];
void dij(int x, int y) {
	memset(dis, -1, sizeof dis);
	for (int j = x; j <= y; j++) {
		dis[j][j] = 0;
		queue<int> q;
		q.push(j);
		while (!q.empty()) {
			int nd = q.front();
			q.pop();
			for (int i = 0; i < int(adj[nd].size()); i++) {
				int to = adj[nd][i].first;
				int cost = adj[nd][i].second;
				if (dis[j][to] == -1 || dis[j][to] > dis[j][nd] + cost) {
					dis[j][to] = dis[j][nd] + cost;
					q.push(to);
				}
			}
		}
	}
}

int main() {
	file();

	int m, s, t, u, v, w, tt, c;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		adj[u].pb(ii(v, w));
		adj[v].pb(ii(u, w));
	}

	dij(1, n);
	for (int i = 1; i <= n; i++)
		adj[i].clear();

	for (int i = 1; i <= n; i++) {
		cin >> tt >> c;
		for (int j = 1; j <= n; j++)
			if (dis[i][j] <= tt && dis[i][j] > 0)
				adj[i].pb(ii(j, c));
	}
	dij(s, s);
	cout << dis[s][t];
	return 0;
}
