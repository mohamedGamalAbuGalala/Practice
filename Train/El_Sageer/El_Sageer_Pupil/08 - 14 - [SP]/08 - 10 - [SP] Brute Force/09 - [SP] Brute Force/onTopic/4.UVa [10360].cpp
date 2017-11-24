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

int main() {
	file();
	int T;
	in(T);
	while (T--) {
		int d, n, k[1025][1025] { 0 }, x, y, mx = -1, pop;
		in(d), in(n);
		for (int i = 0; i < n and in(x) and in(y) and in(pop); ++i)
			for (int j = x - d; j <= x + d; ++j)
				for (int l = y - d; l <= y + d; ++l)
					if (j <= 1024 and l <= 1024 and j >= 0 and l >= 0)
						k[j][l] += pop;
		for (int i = 0; i < 1025; ++i)
			for (int j = 0; j < 1025; ++j)
				if (k[i][j] > mx)
					mx = k[i][j], x = i, y = j;
		ot(x), sp(), ot(y), sp(), ot(mx), ln();
	}
	return 0;
}
