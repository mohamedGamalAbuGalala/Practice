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

string sa[11], sb[11], a, b;
int n, mn;
map<string, bool> vs;

string replace_all(string text, string from, string to, string result = "",
		int i = 0) {
	while (i < sz(text))
		if (i + sz(from) <= sz(text) and text.substr(i, sz(from)) == from)
			result += to, i += sz(from);
		else
			result.pb(text[i++]);
	return result;
}

void slv(string cur, int sm = 0) {
	if (sz(cur) > 10)
		return;
	if (cur == b) {
		mn = min(mn, sm);
		return;
	}
	for (int i = 0; i < n; ++i) {
		string tcur = replace_all(cur, sa[i], sb[i]);
		if (!vs[tcur])
			vs[tcur] = 1, slv(tcur, sm + 1);
	}
}

int main() {
	file(); //TODO
	while (in(n) and n) {
		mn = OO, vs.clear();
		for (int i = 0; i < n and cin >> sa[i] >> sb[i]; ++i)
			;
		cin >> a >> b, vs[a] = 1, slv(a);
		if (mn != OO)
			printf("%d\n", mn);
		else
			printf("-1\n");
	}
	return 0;
}
