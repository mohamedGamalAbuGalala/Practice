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

//#define f first
//#define s second

int main() {
	file(); // TODO
	int n, tt = 0;
	while (cin >> n) {
		int u, m, inDeg[101] { 0 }, cnt = 0;
		vi topo, adj[101];
		map<string, int> sti;
		map<int, string> its;
		string f, t;
		for (int i = 0; i < n and cin >> f; ++i)
			sti[f] = i, its[i] = f;
		in(m);
		for (int i = 0, uu, vv; i < m and cin >> f >> t; ++i)
			uu = sti[f], vv = sti[t], inDeg[vv]++, adj[uu].pb(vv);
		priority_queue<int> pq;
		for (int i = 0; i < n; i++)
			if (!inDeg[i])
				pq.push(-i);
		while (sz(pq)) {
			u = -pq.top(), pq.pop(), topo.pb(u), cnt++;
			for (auto v : adj[u])
				if (!(--inDeg[v]))
					pq.push(-v);
		}
		if (cnt != n) // impossible
			return cout << "There exists a cycle in the graph\n", 0;
		printf("Case #%d: Dilbert should drink beverages in this order:", ++tt);
		for (auto uu : topo)
			sp(), ots(its[uu].c_str());
		otc('.'), ln(), ln();
	}
	return 0;
}
