#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

vector<int> ar[101];
int v[101] = { 0 };

void dfs(int cur) {		// directed graph DFS
	if (v[cur])
		return;
	v[cur] = 1;
	int si = ar[cur].size();
	for (int i = 0; i < si; ++i)
		dfs(ar[cur][i]);
}

int main() {
	freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	int cnt = 0;			// num of connected components
	for (int i = 1; i <= n; ++i) {
		if (v[i]==0) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
/*
6 5
1 2
1 3
2 3
3 4
5 6

 */
