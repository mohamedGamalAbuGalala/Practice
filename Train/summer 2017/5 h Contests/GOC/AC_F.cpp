#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")		//scan new line
#define in(n) scanf("%d",&n)	//scan int
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c ",&n)	//scan char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define inl(n) scanf("%lld",&n)	//scan long long int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define otc(x) printf("%c", x)	//output char
#define ln() printf("\n")		//output new line
#define otl(x) printf("%lld", x)//output long long int
#define otf(x) printf("%.9lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define max3(a,b,c) max(a , max(b , c))
#define min3(a,b,c) min(a , min(b , c))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define s second
#define f first

vii adj[MN];
int vs[MN];
map<int, int> res;

void dfs(int u, int p = -1) {
	bool hch = 0;
	vs[u] = 1;
	for (auto v : adj[u])
		if (!vs[v.f]) {
			hch = 1;
			if (v.s == 2)
				res[p] = -1, dfs(v.f, v.f);
			else
				dfs(v.f, p);
		}
	if (!hch and p != -1 and res[p] != -1)
		res[(p)] = 1;
}

int main() {
	file(); // TODO
	int V, uu, vv, cc;
	in(V);
	for (int i = 0; i < V - 1 and in(uu) and in(vv) and in(cc); ++i)
		adj[uu].pb( { vv, cc }), adj[vv].pb( { uu, cc });
	dfs(1);
	vi ans;
	for (auto &v : res)
		if (v.s > 0)
			ans.pb(v.f);
	ot(sz(ans)), ln();
	for (auto v : ans)
		ot(v), sp();
	return 0;
}
