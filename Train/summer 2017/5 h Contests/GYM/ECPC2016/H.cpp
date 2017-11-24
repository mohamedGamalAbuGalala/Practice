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
	freopen("commandos.in", "r", stdin);	// HERE
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const lli OO = 1e15 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int M[11][11][11], dp[11][11][11], n;
int res(int ff, int y, int x) {
	if (ff < 1 or x > 10 or y > 10)
		return 0;
	int &ret = dp[ff][x][y];
	if (ret == -1)
		ret = M[ff][x][y]
				+ max(res(ff - 1, y, x),
						max(res(ff, y + 1, x), res(ff, y, x + 1)));
	return ret;
}

int main() {
	file();
	int T;
	in(T);
	while (T--) {
		mem(M, 0);
		mem(dp, -1);
		in(n);
		int ff, x, y, h;
		for (int i = 0; i < n; i++)
			in(ff), in(y), in(x), in(h), M[ff][x][y] = h;
		ot(res(10, 1, 1)), ln();
	}
	return 0;
}
