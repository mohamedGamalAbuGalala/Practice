#include <bits/stdc++.h>
using namespace std;
#define f0r(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define mem(a,b) memset(a,b,sizeof a)
// output handle
#define oti(x) printf("%d", x)
#define nl() printf("\n")
#define ots(x) printf("%s", x)	//output char[]
#define otf(x) printf("%.0lf", x)// output double/float with 0.00
#define otl(x) printf("%lld", x)//output long long int
#define space() printf(" ")
// input handle
#define iln() scanf("\n")		//scan new line
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c ",&n)	//scan char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define inl(n) scanf("%lld",&n)	//scan long long int
#define in(n) scanf("%d",&n)	//scan int
#define sz(v) ((int)((v).size()))
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

/*class Unionfind {
 private:
 vector<int> p, rank, setsize;
 int numsets;
 public:
 Unionfind(int N) {
 passingn(N, 0);
 setsize.assing(N, 0);
 numsets = N;
 rank.assing(N,0);
 }
 };

 void unionsets(int i, int j) {
 if (!sameset(i, j)) unmsets--;
 int x = findset(i), y = findset(j);
 if (rank[x] > rank[y]) {
 setsize[x] += setsiz[y];
 p[y] = x;
 } else {
 p[x]=y;

 }
 }*/
typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
	vi p, rank, setSize;                       // remember: vi is vector<int>
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
				if (rank[x] == rank[y]) rank[y]++;
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t, x, y;
	char c;
	string s;
	cin >> t;
	while (t--) {
		int n, cnt(0), cnx(0);
		cin >> n;
		UnionFind UF(n + 5);
		getline(cin, s);
		while (getline(cin, s) && s != "") {
			stringstream ss(s);
			ss >> c >> x >> y;
			if (c == 'c') {
				UF.unionSet(x, y);
			} else if (c == 'q') {
				if (UF.isSameSet(x, y)) cnt++;
				else cnx++;
			}
		}
		cout << cnt << "," << cnx << "\n";
		if (t) cout << "\n";
	}
	return 0;
}
