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
#define otf(x) printf("%.2lf ", x)
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
const int MN = 1e7 + 1;
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
	int ar[101] { 0 }, res[101] { 0 }, v[101] { 0 }, n, m;
	map<int, ii> mp;
	in(n), in(m);
	for (int i = 0; i < m && in(ar[i]); ++i)
		;
	for (int i = 0; i < m - 1; ++i) {
		int nxt = ar[i + 1], cur = ar[i];
		if (nxt <= cur)
			res[cur] = n - cur + nxt;
		else
			res[cur] = nxt - cur;
		if (mp[res[cur]].first != cur and mp[res[cur]].second)
			return ot(-1), 0;
		mp[res[cur]].first = cur, mp[res[cur]].second = 1;
		v[res[cur]] = 1;
	}
	for (int i = 1, j = 1; i <= n; ++i)
		if (!res[i]) {
			while (v[j])
				j++;
			if (j > n)
				return ot(-1), 0;
			res[i] = j, v[j] = 1;
		}
	for (int i = 1; i <= n and ot(res[i]) and sp(); ++i)
		;
	return 0;
}
