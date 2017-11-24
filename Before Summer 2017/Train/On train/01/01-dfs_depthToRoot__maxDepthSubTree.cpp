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

vector<int> ar[101];
int depth[101];

void dfs(int cur, int d) {
	depth[cur] = d;
	int si = ar[cur].size();
	for (int i = 0; i < si; ++i)
		dfs(ar[cur][i], d + 1);
}

int dfs_sub(int cur, int d) {	// max depth subTree
	int ret = d, si = ar[cur].size();
	for (int i = 0; i < si; ++i)
		ret = max(ret, dfs_sub(ar[cur][i], d + 1));
	depth[cur] = ret;
	return ret;
}

int main() {
	file();

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		ar[u].pb(v);
	}
		dfs(1, 0);
//	ot(dfs_sub(1, 0)), ln();
	for (int i = 1; i <= n; ++i) {
		cout << i << " -> " << depth[i] << endl;
	}

	return 0;
}
/*
 *
 8
1 2
1 6
1 8
2 3
2 4
4 5
6 7
 */
