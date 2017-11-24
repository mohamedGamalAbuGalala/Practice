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
typedef pair<lli, string> lls;

#define f first
#define s second
#define WH -1
#define BL 1

vvi adj;
vi low, vs, prnt;
int cnt, root, rch;
vii bridg;

void ArtPoint(int u) {
	low[u] = vs[u] = cnt++;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (vs[v] == WH) {
			bridg.pb( { u, v });
			prnt[v] = u;
			ArtPoint(v);
			if (low[v] > vs[u])
				bridg.pb( { v, u });
			low[u] = min(low[v], low[u]);
		} else if (v != prnt[u]) {
			bridg.pb( { u, v }), low[u] = min(vs[v], low[u]);
			auto idx = lower_bound(all(adj[v]), u);
			if (adj[v][(int) (idx - adj[v].begin())] == u)
				adj[v].erase(idx);
		}
	}
}

int main() {
	file(); //TODO
	int V, tt = 0, u, v, E;
	while (in(V) and in(E) and V and E) {
		ot(++tt), ln(), ln();
		adj.assign(V + 1, vi());
		for (int i = 0; i < E and in(u) and in(v); i++)
			adj[u].pb(v), adj[v].pb(u);
		cnt = 0, vs.assign(V + 1, WH), low.assign(V + 1, 0), prnt.assign(V + 1,
				-1), bridg.clear();
		for (int i = 1; i <= V; i++)
			sort(all(adj[i]));
		for (int i = 1; i <= V; i++)
			if (vs[i] == WH)
				root = i, rch = 0, ArtPoint(i);
		sort(all(bridg));
		for (auto vv : bridg)
			ot(vv.f), sp(), ot(vv.s), ln();
		otc('#'), ln();
	}
	return 0;
}
