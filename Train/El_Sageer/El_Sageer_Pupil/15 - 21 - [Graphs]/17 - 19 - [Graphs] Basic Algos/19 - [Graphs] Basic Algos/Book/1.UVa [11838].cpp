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

vector<vi> adj;
vi vsNum, prnt, low, S, vs;
int numSCC, dfsNumberCounter;

void tarjanSCC(int u) {
	low[u] = vsNum[u] = dfsNumberCounter++, S.pb(u), vs[u] = 1;
	for (auto v : adj[u]) {
		if (vsNum[v] == WH)
			tarjanSCC(v);
		if (vs[v])
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == vsNum[u]) {
		int v;
		numSCC++;
		while (1) {
			v = S.back(), S.pop_back(), vs[v] = 0;
			if (u == v)
				break;
		}
	}
}

int main() {
	file(); //TODO
	int V, E, dr, u, v;
	while (in(V) and in(E) and V and E) {
		adj.assign(V + 1, vi());
		for (int i = 0; i < E and in(u) and in(v) and in(dr); ++i)
			if (dr == 1)
				adj[u].pb(v);
			else
				adj[u].pb(v), adj[v].pb(u);

		vsNum.assign(V + 1, WH), low.assign(V + 1, 0), vs.assign(V + 1, 0);
		dfsNumberCounter = numSCC = 0;
		for (int i = 1; i <= V; i++)
			if (vsNum[i] == WH)
				tarjanSCC(i);
		if (numSCC == 1)
			ot(1), ln();
		else
			ot(0), ln();
	}
	return 0;
}
