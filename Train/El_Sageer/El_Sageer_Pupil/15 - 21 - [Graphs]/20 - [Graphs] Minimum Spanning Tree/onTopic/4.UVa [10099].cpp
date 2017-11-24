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
#define f first
#define s second
#define WH -1
#define BL 1

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int numDisjointSets() {
		return numSets;
	}
	int sizeOfSet(int i) {
		return setSize[findSet(i)];
	}
};
typedef pair<int, ii> iii;
vector<vii> adj;
vi vs;

int dfs(int u, int d) {
	if (u == d)
		return OO;
	vs[u] = 1;
	for (auto v : adj[u])
		if (!vs[v.f]) {
			int dd = dfs(v.f, d);
			if (dd != -1)
				return min(v.s, dd);
		}
	return -1;
}

int main() {
	file(); //TODO
	int V, E, u, v, w, mstC, VV, S, D, PP, tt = 0;
	while (in(V) and in(E) and V and E) {
		adj.assign(V + 1, vii()), mstC = 0, VV = 0;
		vector<iii> edge;
		for (int i = 0; i < E and in(u) and in(v) and in(w); i++)
			edge.push_back(iii(-w, ii(u, v)));
		in(S), in(D), in(PP);
		sort(all(edge));
		UnionFind UF(V + 1);
		for (int i = 0; i < E and VV < V - 1; i++) {
			iii front = edge[i];
			front.f *= -1;
			if (!UF.isSameSet(front.s.f, front.s.s))
				UF.unionSet(front.s.f, front.s.s), mstC += front.f, VV++, adj[front.s.f].pb(
						ii(front.s.s, front.f)), adj[front.s.s].pb(
						ii(front.s.f, front.f));
		}
		vs.assign(V + 1, 0);
		int cst = dfs(S, D), res =
				(cst - 1) ? (PP % (cst - 1) > 0) + PP / (cst - 1) : 0;
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", ++tt, res);
	}
	return 0;
}
