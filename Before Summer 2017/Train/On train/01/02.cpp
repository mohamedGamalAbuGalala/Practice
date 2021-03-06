#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ots(x) printf("%s ", x)
#define otc(x) printf("%c", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(ss) ((int)strlen(s))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e6 + 1e5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

vector<pair<int, int>> ar[101];
int depth[101];

void dfs(int cur, int sum) {		// sum of tree
	depth[cur] = sum;
	int si = ar[cur].size();
	for (int i = 0; i < si; ++i)
		dfs(ar[cur][i].first, sum + ar[cur][i].second);
}

int dfs_sub(int cur, int c) {		// max sum of subTree
	int ret = c, si = ar[cur].size();
	for (int i = 0; i < si; ++i)
		ret = max(ret, dfs_sub(ar[cur][i].first, c + ar[cur][i].second));
	depth[cur] = ret;
	return ret;
}

int main() {
	file();

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		ar[u].pb(make_pair(v, c));
	}
//		dfs(1, 0);
	ot(dfs_sub(1, 0)), ln();
	for (int i = 1; i <= n; ++i)
		cout << i << " -> " << depth[i] << endl;
	return 0;
}

/*
 8
 1 2 1
 1 6 7
 1 8 5
 2 3 3
 2 4 2
 4 5 2
 6 7 3
 */
