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
int gd[26], q;
string good, pat;
bool mat(string pat, string s) {
	if (sz(pat) != sz(s))
		return 0;
	for (int i = 0; i < sz(s); i++)
		if (pat[i] == '?') {
			if (!gd[s[i] - 'a'])
				return 0;
		} else if (s[i] != pat[i])
			return 0;
	return 1;
}
int main() {
	file();
	cin >> good >> pat >> q;
	for (int i = 0; i < sz(good); ++i)
		gd[good[i] - 'a'] = 1;
	string s;
	auto p = pat.find('*');
	while (q--) {
		cin >> s;
		if (sz(s) < sz(pat) - 1)
			puts("NO");
		else if (p == string::npos)
			puts((mat(pat, s) ? "YES" : "NO"));
		else {
			bool ok = 1;
			ok &= mat(pat.substr(0, p), s.substr(0, p));
			reverse(all(pat)), reverse(all(s)), p = sz(pat) - p - 1;
			ok &= mat(pat.substr(0, p), s.substr(0, p));
			reverse(all(pat)), reverse(all(s)), p = sz(pat) - p - 1;
			for (int i = p; i < (sz(s) - (sz(pat) - (int)p - 1)); ++i)
				ok &= !gd[s[i] - 'a'];
			puts((ok ? "YES" : "NO"));
		}
	}
	return 0;
}
