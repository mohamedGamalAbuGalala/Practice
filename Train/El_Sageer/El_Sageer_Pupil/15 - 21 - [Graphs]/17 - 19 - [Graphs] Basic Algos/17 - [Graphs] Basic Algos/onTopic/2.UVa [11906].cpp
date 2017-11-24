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

int R, C, grid[101][101], T, M, N, W, w, xx, yy, tt;
vi dr, dc, od, ev;

void floodfill(int r, int c) {
	if (grid[r][c])
		return;
	grid[r][c] = 1;
	set<ii> st;
	for (int d = 0, rr, cc; d < 8; d++) {
		rr = r + dr[d], cc = c + dc[d];
		if (rr >= 0 and rr < R and cc >= 0 and cc < C and grid[rr][cc] != -1)
			st.insert( { rr, cc }), floodfill(r + dr[d], c + dc[d]);
	}
	if (sz(st) & 1)
		od.pb(1);
	else
		ev.pb(1);
	return;
}

int main() {
	file(); // TODO
	in(T);
	while (T--) {
		in(R), in(C), in(M), in(N), in(W), dr.clear(), dc.clear(), od.clear(), ev.clear(), mem(
				grid, 0);
		dr.pb(M), dr.pb(M), dr.pb(-M), dr.pb(-M), dr.pb(N), dr.pb(N), dr.pb(-N), dr.pb(
				-N), dc.pb(-N), dc.pb(N), dc.pb(-N), dc.pb(N), dc.pb(-M), dc.pb(
				M), dc.pb(-M), dc.pb(M);

		while (W-- and in(xx) and in(yy))
			grid[xx][yy] = -1;
		floodfill(0, 0);
		printf("Case %d: ", ++tt), ot(sz(ev)), sp(), ot(sz(od)), ln();
	}
	return 0;
}
