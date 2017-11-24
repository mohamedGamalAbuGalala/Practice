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
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
const int OO = 1e9 + 5;
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
#define EPS 1e-9

struct point {
	double x, y;   // only used if more precision is needed
	point() {
		x = y = 0.0;
	}                      // default constructor
	point(double _x, double _y) :
			x(_x), y(_y) {
	}        // user-defined
	bool operator <(point other) const { // override less than operator
		if (fabs(x - other.x) > EPS)                 // useful for sorting
			return x < other.x;          // first criteria , by x-coordinate
		return y < other.y;
	}          // second criteria, by y-coordinate
	// use EPS (1e-9) when testing equality of two floating points
	bool operator ==(point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

double dist(point p1, point p2) {                // Euclidean distance
	// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}           // return double

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

#define all(v) v.begin(), v.end()
typedef pair<int, double> iid;
typedef pair<int, int> ii;
typedef vector<iid> vii;
typedef pair<double, ii> iii;
vector<vii> adj;
vector<point> vp;
vector<iii> edge;

int main() { // dfil
	fl(); //TODO
	int T;
	in(T);
	while (T--) {
		int V, u, v, M;
		double w;
		in(V);
		adj.assign(V + 5, vii()), vp.assign(V + 5, point()), edge.clear();
		forr(i,1,V+1 and cin>>(vp[i].x) and cin>>(vp[i].y))
			forr(j,1,i)
			{
				w = dist(vp[i], vp[j]);
				u = j, v = i;
				edge.push_back(iii(w, ii(u, v))), adj[u].pb(iid(v, w)), adj[v].pb(
						iid(u, w));
			}
		sort(all(edge));
		UnionFind UF(V + 5);
		in(M);
		while (M-- and in(u) and in(v))
			UF.unionSet(u, v);
		if (UF.numDisjointSets() == 6)
			puts("No new highways need");
		else
			for (int i = 0; i < sz(edge); i++) {
				iii front = edge[i];
				if (!UF.isSameSet(front.second.first, front.second.second))
					ot(front.second.first), sp(), ot(front.second.second),
					ln(), UF.unionSet(front.second.first,
							front.second.second);
			}
		if (T)
			ln();
	}
	return 0;
}
