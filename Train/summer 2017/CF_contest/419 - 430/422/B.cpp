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
const int MN = 1e5 + 5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<lli, string> lls;

int main() {
	file();
	int mn, dd = 0;
	string s, t;
	map<int, vi> mp;
	in(mn), in(mn), mn = OO;
	cin >> s >> t;
	for (int i = 0; i < sz(t) - sz(s) + 1; dd = 0, ++i) {
		vi dif;
		for (int j = 0; j < sz(s); ++j)
			if (s[j] != t[i + j])
				dd++, dif.pb(j + 1);
		if (mn > dd)
			mn = dd, mp[mn] = dif;
	}
	ot(mn), ln();
	for (int i = 0; i < sz(mp[mn]); ++i)
		ot(mp[mn][i]);
	return 0;
}
