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

#define f first.first
#define s first.second
#define ss second
vector<pair<ii, int>> v;

void clc(int x, int y, int r) {
	for (int i = 0; i < sz(v); ++i) {
		if (v[i].ss)
			continue;
		int xx = v[i].f, yy = v[i].s;
		int fs = xx - x, ss = yy - y;
		fs *= fs, ss *= ss;
		double res = sqrt(fs + ss);
		if (res <= (double) r)
			v[i].ss = 1;
	}
}
int main() {
	file();
	ii lt, ld, rt, rd;
	int n, x, y, r, ans = 0, x1, x2, y1, y2;
	in(x1), in(y1), in(x2), in(y2);
	lt.first = min(x1, x2), lt.second = max(y1, y2);
	ld.first = min(x1, x2), ld.second = min(y1, y2);
	rt.first = max(x1, x2), rt.second = max(y1, y2);
	rd.first = max(x1, x2), rd.second = min(y1, y2);
	for (int i = ld.first; i < rd.first; ++i)
		v.pb( { { i, ld.second }, 0 });
	for (int i = rt.first; i > lt.first; --i)
		v.pb( { { i, rt.second }, 0 });
	for (int i = rd.second; i < rt.second; ++i)
		v.pb( { { rd.first, i }, 0 });
	for (int i = lt.second; i > ld.second; --i)
		v.pb( { { lt.first, i }, 0 });
	in(n);
	for (int i = 0; i < n and in(x) and in(y) and in(r); ++i)
		clc(x, y, r);
	for (int i = 0; i < sz(v); ++i)
		if (!v[i].ss)
			ans++;
	ot(ans);
	return 0;
}
