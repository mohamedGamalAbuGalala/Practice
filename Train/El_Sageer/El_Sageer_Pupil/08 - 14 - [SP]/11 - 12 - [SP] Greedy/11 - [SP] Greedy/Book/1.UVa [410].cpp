#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")		//scan new line
#define in(n) scanf("%d",&n)	//scan int
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c",&n)	//scan char
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
	freopen("ot.txt", "w", stdout);
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
	file(); //TODO
	int c, s, ar[11], set = 0;
	while (in(c) == 1 and in(s) == 1) {
		int sor[11] { 0 };
		printf("Set #%d\n", (++set));
		double avg = 0, im = 0;
		for (int i = 0; i < s and in(ar[i]); sor[i] = ar[i], avg += ar[i], ++i)
			;
		avg /= c;
		sort(sor, sor + 2 * c);
		vi oo[13];
		for (int i = 0; i < c; ++i) {
			int idx1 = -1, idx2 = -1, s1 = sor[i], s2 = sor[2 * c - 1 - i];
			for (int i = 0; i < s; ++i) {
				if (s1 == ar[i])
					idx1 = i;
				if (s2 == ar[i])
					idx2 = i;
			}
			if (!s1 or !s2) {
				if (s1)
					oo[idx1].pb(s1);
				if (s2)
					oo[idx2].pb(s2);
			} else {
				if (idx1 > idx2)
					oo[idx2].pb(s2), oo[idx2].pb(s1);
				else
					oo[idx1].pb(s1), oo[idx1].pb(s2);
			}
			if (idx1 >= 0)
				ar[idx1] = -1;
			if (idx2 >= 0)
				ar[idx2] = -1;
			im += abs((s1 + s2) - avg);
		}
		int cnt = 0;
		for (int i = 0; i < 13; ++i)
			if (sz(oo[i])) {
				printf("%2d:", cnt++);
				for (int j = 0; j < sz(oo[i]); ++j)
					printf(" %d", (oo[i][j]));
				ln();
			}
		for (int i = cnt; i < c; ++i)
			printf("%2d:\n", i);
		printf("IMBALANCE = %.5lf\n\n", im);
	}
	return 0;
}
