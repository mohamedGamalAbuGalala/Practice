/*
 Notes::

 Input::
3 2
1 2
2 3
 Output::
YES
 */
#include <bits/stdc++.h>

#define INF 1000000000
#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi ar[10001];
int v[10001], loop;

void dfs(int cur) {
	if (v[cur]) {
		loop++;
		return;
	}
	v[cur] = 1;
	for (int i = 0; i < (int) ar[cur].size(); ++i)
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
	}
	int c = 0;
	for (int i = 1; i <= n; ++i)
		if (!v[i]) {
			c++;
			dfs(i);
		}
	if (c <= 1 && !loop)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
