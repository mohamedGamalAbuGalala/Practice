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
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

void split(const string &s, const char* delim, vector<string> & v) {
	// to avoid modifying original string
	// first duplicate the original string and return a char pointer then free the memory
	char * dup = strdup(s.c_str());
	char * token = strtok(dup, delim);
	while (token != NULL) {
		v.push_back(string(token));
		// the call is treated as a subsequent calls to strtok:
		// the function continues from where it left in previous invocation
		token = strtok(NULL, delim);
	}
	free(dup);
}

int main() {
	file();
	int T;
	in(T);
	while (T--) {
		string s1, s2, p, m, c;
		cin >> s1 >> s2;
		vector<string> sp1, sp2;
		map<string, string> mp1, mp2;
		split(s1, "{:,}", sp1), split(s2, "{:,}", sp2);
		for (int i = 0; i < sz(sp1); i += 2)
			mp1[sp1[i]] = sp1[i + 1];
		for (int i = 0; i < sz(sp2); i += 2)
			mp2[sp2[i]] = sp2[i + 1];
		for (auto it : mp2)
			if (mp1.find(it.first) == mp1.end())
				p += (sz(p)) ? "," + (it.first) : (it.first);
			else if (mp1[it.first] != mp2[it.first])
				c += (sz(c)) ? "," + (it.first) : (it.first);
		for (auto it : mp1)
			if (mp2.find(it.first) == mp2.end())
				m += (sz(m)) ? "," + (it.first) : (it.first);
		if (!sz(m) and !sz(p) and !sz(c))
			puts("No changes");
		if (sz(p))
			otc('+'), ots(p.c_str()), ln();
		if (sz(m))
			otc('-'), ots(m.c_str()), ln();
		if (sz(c))
			otc('*'), ots(c.c_str()), ln();
		ln();
	}
	return 0;
}
