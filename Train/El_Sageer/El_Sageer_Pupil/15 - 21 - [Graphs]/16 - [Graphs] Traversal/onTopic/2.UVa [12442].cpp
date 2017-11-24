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
const int MN = 5e4 + 1e2;
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

int T, N, vs[MN], mx, i, cmx, ans, reachable[MN], nxt[MN], counter;

int dfs(int u, int com = 0) {
	vs[u] = ++counter;
	reachable[u] = 1;
	int cycleHead = -1;

	int v = nxt[u];
	if (vs[v] == 0) {
		cycleHead = dfs(v);
		if (cycleHead != -1)
			reachable[u] = reachable[v];		// in  the same cycle
		else
			reachable[u] += reachable[v];// pointing to element point to calculated cycle
	} else if (vs[v] == -1)
		reachable[u] += reachable[v];			// point to calculated cycle
	else
		reachable[u] = vs[u] - vs[v] + 1, cycleHead = v;	// we make a cycle
	vs[u] = -1;
	return cycleHead == u ? -1 : cycleHead;
}

int main() {
	file(); // TODO
	in(T);
	int u, v;
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case %d: ", tt), mem(vs, 0), in(N), mx = 0, ans = 1, counter = 0;
		for (i = 0; i < N and in(u) and in(v); ++i)
			nxt[u] = (v);
		for (i = 1; i <= N; ++i)
			if (!vs[i])
				dfs(i);
		ans = 0;
		for (int i = 1; i <= N; ++i)
			if (reachable[i] > reachable[ans])
				ans = i;
		ot(ans), ln();
	}
	return 0;
}
