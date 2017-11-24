#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
// constants
const int MN = 2e6 + 1e3;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int main() {
	file();
	int x, n;
	lli ans = 1;
	vi idx;
	in(n);
	for (int i = 0; i < n and in(x); ++i)
		if (x)
			idx.pb(i);
	if (!sz(idx) or sz(idx) == 1)
		return ot(sz(idx)), 0;
	else
		for (int i = 0; i < sz(idx) - 1; ans *= idx[i + 1] - idx[i], ++i)
			;
	otl(ans);
	return 0;
}
