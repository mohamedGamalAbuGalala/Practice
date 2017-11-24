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

const lli maxN = 1e5 + 10;
const lli maxE = 1e5 + 10;

int colors[200005];
int m = -1;
vi ar[200005];

void dfs(int ind, int ll, int l) {
	int cnt = 1;
	for (int i = 0; i < (int) ar[ind].size(); ++i) {
		if (!colors[ar[ind][i]]) {
			if (cnt == ll || cnt == l)
				i--;
			else {
				colors[ar[ind][i]] = cnt;
				m = max(m, cnt);
				dfs(ar[ind][i], l, cnt);
			}
			cnt++;
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		ar[u].pb(v);
		ar[v].pb(u);
	}
	colors[1] = 1;
	dfs(1, 0, 1);
	printf("%d\n", m);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", colors[i]);
	}
	return 0;
}
