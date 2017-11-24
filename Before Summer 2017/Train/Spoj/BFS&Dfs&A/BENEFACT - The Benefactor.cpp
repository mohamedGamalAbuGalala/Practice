/*
 Notes::

 Input::
 Output::

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
typedef vector<vector<ii>> vvii;

const lli maxN = 50000 + 10;
const lli maxE = 1e5 + 10;

vvii ar;
int v[maxN], res, ind;

void dfs(int cur, int cost) {
	if (res < cost)
		res = cost, ind = cur;
	v[cur] = 1;
	for (int i = 0; i < (int) ar[cur].size(); ++i)
		if (!v[ar[cur][i].first])
			dfs(ar[cur][i].first, cost + ar[cur][i].second);
	v[cur] = 0;
}

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		ar = vvii(n + 1);
		for (int i = 0; i < n - 1; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			ar[u].pb(ii(v, c));
			ar[v].pb(ii(u, c));
		}
		res = 0, ind =  0;
		dfs(1,0);
		res = 0;
		dfs(ind,0);
		cout << res << "\n";
	}
}
