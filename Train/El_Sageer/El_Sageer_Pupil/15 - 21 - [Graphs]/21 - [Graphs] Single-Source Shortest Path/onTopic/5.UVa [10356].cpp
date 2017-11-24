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
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
#define ff first
#define ss second
#define WH -1
#define BL 1

int main() {
	file(); //TODO
	int V, E, tt = 0;
	vector<vii> adj, gr;
	vi dist;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	ii front;
	while (in(V) == 1 and in(E) == 1) {
		adj.assign(V + 1, vii()), gr.assign(V + 1, vii());
		for (int i = 0, u, v, w; i < E and in(u) and in(v) and in(w); ++i)
			gr[u].pb(ii(v, w)), gr[v].pb(ii(u, w));
		for (int i = 0; i < V; ++i)
			for (auto u : gr[i])
				for (auto v : gr[u.ff])
					adj[i].pb(ii(v.ff, (v.ss + u.ss)));
		dist.assign(V, OO), dist[0] = 0, pq.push(ii(0, 0));
		while (sz(pq)) {
			front = pq.top(), pq.pop();
			int d = front.ff, u = front.ss;
			if (d > dist[u])
				continue;
			for (auto &v : adj[u])
				if (dist[u] + v.ss < dist[v.ff]) {
					dist[v.ff] = dist[u] + v.ss;
					pq.push(ii(dist[v.first], v.first));
				}
		}
		printf("Set #%d\n", ++tt);
		if (dist[V - 1] == OO)
			puts("?");
		else
			ot(dist[V - 1]), ln();
	}
	return 0;
}
