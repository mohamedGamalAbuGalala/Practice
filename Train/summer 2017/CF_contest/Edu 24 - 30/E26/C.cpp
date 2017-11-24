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

#define f first
#define s second

int main() {
	file(); // TODO
	int n, a, b, ans = 0, x[101], y[101];
	in(n), in(a), in(b);
	for (int i = 0; i < n and in(x[i]) and in(y[i]); ++i)
		;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			if ((x[i] + y[j] <= a and y[i] <= b and x[j] <= b)
					or (x[i] + x[j] <= a and y[i] <= b and y[j] <= b)
					or (y[i] + x[j] <= a and x[i] <= b and y[j] <= b)
					or (y[i] + y[j] <= a and x[i] <= b and x[j] <= b)) {
				ans = max(ans, x[i] * y[i] + x[j] * y[j]);
			}
			if ((x[i] + y[j] <= b and y[i] <= a and x[j] <= a)
					or (x[i] + x[j] <= b and y[i] <= a and y[j] <= a)
					or (y[i] + x[j] <= b and x[i] <= a and y[j] <= a)
					or (y[i] + y[j] <= b and x[i] <= a and x[j] <= a)) {
				ans = max(ans, x[i] * y[i] + x[j] * y[j]);
			}
		}
	ot(ans);
	return 0;
}
