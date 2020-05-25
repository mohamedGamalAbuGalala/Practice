#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x)
#define sp() printf(" ")
#define ots(x) printf("%s", x)
#define otc(x) printf("%c", x)
#define ln() printf("\n")
#define otl(x) printf("%lld", x)
#define otf(x) printf("%.14lf", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(s) ((int)strlen(s))
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
const int MN = 1e9 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))

int main() {
	file();
	int n, f[21] { 0 }, c[21] { 0 }, m, v, t;
	in(n);
	for (int o = 0; o < n and in(f[o]) and in(c[o]); ++o)
		;
	in(m);
	for (int k = 1; k <= m and in(v) and in(t); ++k) {
		int ans = OO;
		printf("Case %d: ", k);
		for (int i = 1; i < (1 << n); ++i) {
			int sm = 0, vv = v;
			for (int j = 0; j < n; ++j)
				if (isOn(i, j))
					sm += c[j], vv -= (f[j] * t);
			if (vv <= 0 and sm < ans)
				ans = sm;
		}
		if (ans == OO)
			puts("IMPOSSIBLE");
		else
			ot(ans), ln();
	}
	return 0;
}
