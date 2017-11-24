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

vector<vii> adj;
vi vs, prnt, low, articulation_vertex;
int dfsCounter, Root, rootChildren;

void articulationPointAndBridge(int u) {
	low[u] = vs[u] = dfsCounter++;
	for (auto v : adj[u])
		if (vs[v.f] == WH) {
			prnt[v.f] = u;
			if (u == Root)
				rootChildren++;

			articulationPointAndBridge(v.f);

			if (low[v.f] >= vs[u])
				articulation_vertex[u] = 1;
			if (low[v.f] > vs[u])
				printf(" Edge (%d, %d) is a bridge\n", u, v.f);
			low[u] = min(low[u], low[v.f]);
		} else if (v.f != prnt[u])
			low[u] = min(low[u], vs[v.f]);
}

int main() {
	file(); //TODO
	int V, total_neighbors, id, weight;

	/*
	 // Left graph in Figure 4.6/4.7/4.8
	 6
	 1 1 0
	 3 0 0 2 0 4 0
	 1 1 0
	 1 4 0
	 3 1 0 3 0 5 0
	 1 4 0

	 // Right graph in Figure 4.6/4.7/4.8
	 6
	 1 1 0
	 5 0 0 2 0 3 0 4 0 5 0
	 1 1 0
	 1 1 0
	 2 1 0 5 0
	 2 1 0 4 0
	 */

	in(V), adj.assign(V, vii());
	for (int i = 0; i < V and in(total_neighbors); i++)
		for (int j = 0; j < total_neighbors and in(id) and in(weight); j++)
			adj[i].pb( { id, weight });

	ots("Articulation Points & Bridges (the input graph must be UNDIRECTED)\n");
	dfsCounter = 0;
	vs.assign(V, WH);
	low.assign(V, 0);
	prnt.assign(V, -1);
	articulation_vertex.assign(V, 0);
	ots("Bridges:\n");
	for (int i = 0; i < V; i++)
		if (vs[i] == WH) {
			Root = i, rootChildren = 0, articulationPointAndBridge(i);
			articulation_vertex[Root] = (rootChildren > 1);
		}
	ots("Articulation Points:\n");
	for (int i = 0; i < V; i++)
		if (articulation_vertex[i])
			printf(" Vertex %d\n", i);

	return 0;
}
