#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x)
#define sp() printf(" ")
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
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

vi ar[101];
int vis[101];

void bfs(int s, int sz = 1, int cur = 0) {
	queue<int> q;
	q.push(s);
	for (; sz(q); sz = sz(q))
		while (sz--) {
			cur = q.front(), q.pop();
			for (int it = 0; it < sz(ar[cur]); it++)
				if (!vis[ar[cur][it]])
					vis[ar[cur][it]] = 1, q.push(ar[cur][it]);
		}
}

int main() {
	file();
	int n, u, v, x;
	while (in(n) and n) {
		for (int i = 0; i <= n; ++i)
			ar[i].clear();
		for (int i = 0; in(u) and u; ++i)
			while (in(v) and v)
				ar[u].pb(v);
		in(x);
		for (int i = 0; i < x and in(u); ++i) {
			mem(vis, 0);
			bfs(u);
			vi res;
			for (int j = 1; j <= n; ++j)
				if (!vis[j])
					res.pb(j);
			ot(sz(res));
			if (sz(res))
				sp();
			for (int it = 0; it < sz(res); it++) {
				ot(res[it]);
				if (it < sz(res) - 1)
					sp();
			}
			ln();
		}
	}
	return 0;
}
