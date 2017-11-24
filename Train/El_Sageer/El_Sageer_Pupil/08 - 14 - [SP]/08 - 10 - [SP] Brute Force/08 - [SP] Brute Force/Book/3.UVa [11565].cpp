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
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 2e6 + 1e2;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int main() {
	file();
	int t;
	in(t);
	while (t--) {
		lli f = 0, x, y, z, a, b, c, mn = OO, mx = -1, md;
		in(a), in(b), in(c);
		for (x = -22; x < 23 and !f; ++x)
			if (x * x <= c)
				for (y = -100; y < 101 and !f; ++y)
					if (y != x and x * x + y * y <= c)
						for (z = -100; z < 101 and !f; ++z)
							if (x != z and y != z and x + y + z == a
									and x * y * z == b
									and x * x + y * y + z * z == c)
								mn = min(x, min(y, z)), mx = max(x, max(y, z)), md =
										(mn != x and mx != x) ? x :
										(mn != y and mx != y) ? y : z, ot(mn), sp(), ot(
										md), sp(), ot(mx), f = 1;
		if (!f)
			ots("No solution.");
		ln();
	}
	return 0;
}
