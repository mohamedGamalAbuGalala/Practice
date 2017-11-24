#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}

#define sp() printf(" ")		//output single space
typedef vector<int> vi;
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ln() printf("\n")		//output new line
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
const int OO = 1e9 + 5;

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

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

#define ff first
#define ss second
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
vector<vii> adj;

vector<iii> edge;

int second_mst(int V, int F, int T) {
	int SmstC = 0, VV = 0;
	UnionFind UF(V);
	for (auto it : edge) {
		if (!(VV < V - 1))
			break;
		int frm = it.ss.ff, too = it.ss.ss;
		if (frm == F and too == T)
			continue;
		if (!UF.isSameSet(frm, too))
			UF.unionSet(frm, too), SmstC += it.ff;
	}
	if (UF.numDisjointSets() != 1)
		return OO;
	return SmstC;
}

int main() { // dfil
	fl(); //TODO
	int T;
	in(T);
	while (T--) {
		int V, E, u, v, w, VV, mstC;
		vector<iii> MST;
		in(V), in(E), adj.assign(V, vii()), mstC = VV = 0, edge.clear();
		for (int i = 0; i < E and in(u) and in(v) and in(w); i++)
			u--, v--, edge.push_back(iii(w, ii(u, v))), adj[u].pb(ii(v, w)), adj[v].pb(
					ii(u, w));
		sort(all(edge));
		UnionFind UF(V);
		for (auto it : edge) {
			if (!(VV < V - 1))
				break;
			int frm = it.ss.ff, too = it.ss.ss;
			if (!UF.isSameSet(frm, too))
				MST.pb(iii(it.ff, ii(frm, too))), UF.unionSet(frm, too), VV++, mstC +=
						it.ff;
		}
		int s1 = mstC, s2 = OO;
		for (auto it : MST)
			s2 = min(s2, second_mst(V, it.ss.ff, it.ss.ss));
		if (s2 == OO)
			ot(s1), sp(), ot(s1), ln();
		else
			ot(s1), sp(), ot(s2), ln();
	}
	return 0;
}
