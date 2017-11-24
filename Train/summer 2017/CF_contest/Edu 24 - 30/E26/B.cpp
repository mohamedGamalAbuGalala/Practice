#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")		//scan new line
#define in(n) scanf("%d",&n)	//scan int
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c ",&n)	//scan char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define inl(n) scanf("%lld",&n)	//scan long long int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define otc(x) printf("%c", x)	//output char
#define ln() printf("\n")		//output new line
#define otl(x) printf("%lld", x)//output long long int
#define otf(x) printf("%.9lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
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
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int main() {
	file(); // TODO
	int n, m;
	char s[101][101];
	in(n), in(m);
	for (int i = 0; i < n and ins(s[i]); ++i)
		;
	int hz = !(n % 3) ? n / 3 : -1, vz = !(m % 3) ? m / 3 : -1;
	bool hs = 1, vs = 1, r = 0, g = 0, b = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == 'R')
				r = 1;
			else if (s[i][j] == 'G')
				g = 1;
			else if (s[i][j] == 'B')
				b = 1;
	if (r and g and b) {
		char cur;
		if (hz != -1) {
			int hh[] { 0, 0, hz, hz * 2 };
			for (int i = 1; i <= 3; ++i) {
				cur = s[hh[i]][0];
				for (int j = hh[i]; j < hz * i; ++j)
					for (int k = 0; k < m; ++k)
						if (s[j][k] != cur)
							hs = 0;
			}
		} else
			hs = 0;
		if (vz != -1) {
			int vv[] { 0, 0, vz, vz * 2 };
			for (int i = 1; i <= 3; ++i) {
				cur = s[0][vv[i]];
				for (int j = vv[i]; j < vz * i; ++j)
					for (int k = 0; k < n; ++k)
						if (s[k][j] != cur)
							vs = 0;
			}
		} else
			vs = 0;
	} else
		vs = 0, hs = 0;
	if (vs or hs)
		puts("YES");
	else
		puts("NO");
	return 0;
}
