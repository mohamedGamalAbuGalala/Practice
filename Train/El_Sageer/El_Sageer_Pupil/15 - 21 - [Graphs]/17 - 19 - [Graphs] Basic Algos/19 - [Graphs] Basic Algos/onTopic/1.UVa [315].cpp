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
set<int> ArV;
int cnt, root, rch;

void ArtPoint(int u) {
	low[u] = vs[u] = cnt++;
	for (auto v : adj[u])
		if (vs[v] == WH) {
			prnt[v] = u;
			if (u == root)
				rch++;
			ArtPoint(v);
			if (low[v] >= vs[u] and u != root)
				ArV.insert(u);
			if (low[v] > vs[u]) {
				// bridge edge
			}
			low[u] = min(low[v], low[u]);
		} else if (v != prnt[u])
			low[u] = min(vs[v], low[u]);
}

int main() {
	file(); //TODO
	int V, vcnt = 0, u, v;
	string lin;
	while (in(V) and V) {
		adj.assign(V + 1, vi()), vcnt = 0;
		while (getline(cin, lin) and lin[0] != '0') {
			stringstream sss(lin);
			sss >> u, vcnt++;
			while (sss >> v)
				adj[u].pb(v), adj[v].pb(u), vcnt++;
		}
		cnt = 0, vs.assign(V + 1, WH), low.assign(V + 1, 0), prnt.assign(V + 1,
				-1), ArV.clear();
		for (int i = 1; i <= V; i++)
			if (vs[i] == WH) {
				root = i, rch = 0, ArtPoint(i);
				if (rch > 1)
					ArV.insert(i);
			}
		ot(sz(ArV)), ln();
	}
	return 0;
}
