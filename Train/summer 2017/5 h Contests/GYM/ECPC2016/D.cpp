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
#else
	freopen("popcorn.in", "r", stdin);	// HERE
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 2e6 + 1e2;
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
	int s;
	cin >> s;
	while (s--) {
		int n, m;
		cin >> n >> m;
		int big = max(m, n - m);
		int small = n - big;
		int a[101], b[101];// HERE
		for (int i = n, j = 0; i > big; i--, j++)
			a[j] = i;
		for (int i = 1; i <= small; i++)
			b[i - 1] = i;
		sort(b, b + small, greater<int>());
		for (int i = 0; i < small; i++) {
			for (int j = 0; j < small; j++) {
				int g = __gcd(a[i], b[j]);
				a[i] /= g;
				b[j] /= g;
			}
		}
		unsigned long long ans = 1;
		for (int i = 0; i < small; i++) {
			ans *= a[i];
		}
		cout << ans << endl;

	}
	return 0;
}
