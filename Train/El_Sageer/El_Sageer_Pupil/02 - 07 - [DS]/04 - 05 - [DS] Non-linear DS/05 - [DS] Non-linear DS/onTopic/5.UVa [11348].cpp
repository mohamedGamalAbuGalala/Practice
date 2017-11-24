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
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.6lf", x)
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
const int MN = 1e5 + 1e2;
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
	int T, tt = 0;
	in(T);
	while (T--) {
		map<int, set<int>> mp;
		int n, m, x, sm = 0, ar[52] { 0 };
		in(n);
		for (int i = 1; i <= n and in(m); ++i)
			while (m--)
				in(x), mp[x].insert(i);
		for (auto it : mp)
			if (sz(mp[it.first]) == 1)
				ar[*mp[it.first].begin()]++, sm++;
		if (!sm) {
			ots("Case "), ot(++tt), ots(": "), ln();
			continue;
		}
		ots("Case "), ot(++tt), otc(':');
		for (int i = 1; i <= n; ++i)
			sp(), otf(100 * ((double )ar[i] / (double )sm)), otc('%');
		ln();
	}
	return 0;
}
