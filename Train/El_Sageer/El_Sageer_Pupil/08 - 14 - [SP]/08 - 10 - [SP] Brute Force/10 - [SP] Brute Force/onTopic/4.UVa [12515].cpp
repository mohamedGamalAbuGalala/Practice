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
#define otf(x) printf("%.2lf", x)
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
	file(); //TODO
	int m, qq;
	in(m), in(qq);
	char db[1001][102], q[102];
	for (int i = 0; i < m and ins(db[i]); ++i)
		;
	for (int i = 0; i < qq and ins(q); ++i) {
		int ans = -1, mx = OO;
		for (int j = 0; j < m; ++j) {
			int md = OO;
			if (ssz(db[j]) >= ssz(q))
				for (int k = 0; k < ssz(db[j]); ++k) {
					if (k + ssz(q) <= ssz(db[j])) {
						int ddf = 0;
						for (int m = 0; m < ssz(q); ++m)
							if (q[m] != db[j][k + m])
								ddf++;
						md = min(ddf, md);
					}
				}
			if (md < mx)
				mx = md, ans = j + 1;
		}
		ot(ans), ln();
	}

	return 0;
}
