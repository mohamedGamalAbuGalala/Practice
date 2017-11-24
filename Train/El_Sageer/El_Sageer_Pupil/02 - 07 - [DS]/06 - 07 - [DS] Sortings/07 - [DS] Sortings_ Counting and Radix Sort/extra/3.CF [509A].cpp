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

int slv(int i, int j) {
	if (i == 1 or j == 1)
		return 1;
	return slv(i - 1, j) + slv(i, j - 1);
}

int main() {
	file();
	int n;
//	int ar[11][11] { 0 }, mx = 1;
	in(n);
	ot(slv(n, n));
//	for (int i = 0; i < n; ++i)
//		ar[0][i] = 1, ar[i][0] = 1;
//	for (int i = 1; i < n; ++i)
//		for (int j = 1; j < n; ++j)
//			ar[i][j] = ar[i - 1][j] + ar[i][j - 1], mx = max(mx, ar[i][j]);
//	ot(mx);
	return 0;
}
