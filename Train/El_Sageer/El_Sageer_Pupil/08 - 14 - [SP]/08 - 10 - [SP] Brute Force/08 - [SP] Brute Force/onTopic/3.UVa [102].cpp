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

int main() {
	file();

	int ar[10];
	while (in(ar[1]) == 1) {
		for (int i = 2; i <= 9 and in(ar[i]); ++i)
			;
		int mn = OO;
		string bcg = "BGC", ans = "GCB";
		map<string, int> mp;
		for (int i = 1; i < 4; ++i)
			for (int j = 1; j < 4; ++j)
				for (int k = 1; i != j and k < 4; ++k) {
					if (k == j or k == i)
						continue;
					int sm = ar[i + 3] + ar[i + 6] + ar[j] + ar[j + 6] + ar[k]
							+ ar[k + 3];
					string s = "...";
					s[0] = bcg[i - 1], s[1] = bcg[j - 1], s[2] = bcg[k - 1];
					if (sm < mn)
						mn = sm, ans = s;
					else if (sm == mn)
						ans = min(ans, s);
				}
		cout << ans, otc(' '), ot(mn), ln();
	}
	return 0;
}
