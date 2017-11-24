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
#define otf(x) printf("%.2lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
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
const int MN = 1e6 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

const int N = (int) 1e5 + 123;
const int C = 101;
const int P = 11;

int n, q, c;
int com[P][C][C];

int main() {
	file(); // TODO
	in(n), in(q), in(c);
	for (int i = 0, x, y, s; i < n and in(x) and in(y) and in(s);
			com[s][x][y]++, ++i)
		;
	for (int p = 0; p <= c; ++p)
		for (int i = 1; i < C; ++i)
			for (int j = 1; j < C; ++j)
				com[p][i][j] += com[p][i - 1][j] + com[p][i][j - 1]
						- com[p][i - 1][j - 1];
	for (int i = 0, ans, t, x1, x2, y1, y2;
			i < q and in(t) and in(x1) and in(y1) and in(x2) and in(y2); ++i) {
		ans = 0;
		for (int p = 0, br, am; p <= c; ++p) {
			br = (p + t) % (c + 1);
			am = com[p][x2][y2] - com[p][x1 - 1][y2] - com[p][x2][y1 - 1]
					+ com[p][x1 - 1][y1 - 1];
			ans += am * br;
		}
		ot(ans), ln();
	}
	return 0;
}
