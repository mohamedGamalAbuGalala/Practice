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

vi adj[1005];
queue<int> q;
int vs[1005], u, cst[1005];
int n, m, ss, e, x, ar[MN];

int main() {
	file(); // TODO
	in(n), in(m), in(ss), in(e), in(ar[1]);
	if (ss > e)
		swap(ss, e);
	for (int i = 2; i <= n and in(x); ar[i] = x, ++i)
		if (ar[i - 1] + 1 == x or ar[i - 1] - 1 == x)
			adj[x].pb(ar[i - 1]), adj[ar[i - 1]].pb(x);
	if (ar[ss] == ar[e])
		return ot(0), 0;
	q.push(ar[e]), vs[ar[e]] = 1, cst[ar[e]] = 0;
	for (int sz = 1; sz(q); sz = sz(q))
		while (sz--) {
			u = q.front(), q.pop();
			for (int &v : adj[u])
				if (!vs[v]) {
					q.push(v), cst[v] = cst[u] + 1, vs[v] = 1;
					if (v == ar[ss])
						return ot(cst[v]), 0;
				}
		}
	ot(-1);
	return 0;
}
/*
5 5 5 1
1 3 2 4 5

can he move to port 3 with house 2 from port 1 with house 1
using this sample ::


 */
