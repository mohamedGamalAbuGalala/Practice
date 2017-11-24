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
#define otf(x) printf("%.2lf", x)// output double/float with 0.00
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
const int MN = 1e6 + 1e2;
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
	int n, pp[105], T, l;
	bool sm[105], v[105];
	char type, sep;
	in(T);
	for (int t = 1; t <= T; ++t) {
		in(n), in(l);
		for (int i = 0; i < n and cin >> type >> sep >> pp[i];
				sm[i] = (type == 'S'), v[i] = 0, ++i)
			;
		sm[n] = 0, pp[n] = l, v[n] = 0;
		int mx = pp[0];
		for (int i = 0; i < n; ++i) {
			v[i] = 1;
			if (!sm[i + 1])
				mx = max(mx, pp[i + 1] - pp[i]);
			else
				mx = max(mx, pp[i + 2] - pp[i]), ++i;
		}
		for (int i = n; i > 0; --i)
			if (!v[i - 1] or !sm[i - 1])
				mx = max(mx, pp[i] - pp[i - 1]);
			else
				mx = max(mx, pp[i] - pp[i - 2]), --i;
		printf("Case %d: %d\n", t, mx);
	}
	return 0;
}
