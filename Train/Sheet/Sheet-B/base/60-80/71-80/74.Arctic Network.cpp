#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("ot.txt", "w", stdout);
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

#define ff first
#define ss second
typedef pair<int, double> iid;
typedef pair<int, int> ii;
typedef vector<iid> vii;
typedef pair<double, ii> iii;

vector<vii> adj;
vector<point> vp;
vector<iii> edge;

bool cmp(const iii& lhs, const iii& rhs) {
	return lhs.ff < rhs.ff;
}

int main() { // dfil
	fl(); //TODO
	int T, K, V;
	in(T);
	while (T-- and in(K) and in(V)) {
		int VV = 0, u, v;
		double w, mstC = -1;
		adj.assign(V, vii()), vp.assign(V, point()), edge.clear();
		forr(i,0,V and cin>>(vp[i].x) >>(vp[i].y))
			forr(j,0,i)
			{
				w = dist(vp[i], vp[j]);
				u = j, v = i;
				edge.push_back(iii(w, ii(u, v))), adj[u].pb(iid(v, w)), adj[v].pb(
						iid(u, w));
			}
		sort(all(edge));
		UnionFind UF(V);
		for (auto it : edge) {
			if (!(VV < V - 1) or UF.numDisjointSets() == K)
				break;
			int frm = it.ss.ff, too = it.ss.ss;
			if (!UF.isSameSet(frm, too))
				UF.unionSet(frm, too), VV++, mstC =
						(mstC < it.ff) ? it.ff : mstC + 1 - 1;
		}
		printf("%.2lf", mstC), ln();
	}
	return 0;
}
