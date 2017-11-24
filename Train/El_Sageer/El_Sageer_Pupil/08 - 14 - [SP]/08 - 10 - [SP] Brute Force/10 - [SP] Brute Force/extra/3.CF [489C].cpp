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
#define otf(x) printf("%.2lf", x)
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

bool can(int m, int s) {
	return s >= 0 && s <= 9 * m;
}

int main() {
	file(); //TODO
	int m, s;
	in(m), in(s);
	if (m == 1 and s == 0)
		return puts("0 0"), 0;
	string minn, maxx;
	int sm1 = s, sm2 = s;
	for (int i = 0; i < m; i++)
		for (int d = 0, dmn = 0, dmx = 0; d < 10 and (!dmn or !dmx); d++) {
			if (!dmn and (i > 0 or d > 0) and can(m - i - 1, sm1 - d))
				minn += char('0' + d), sm1 -= d, dmn = 1;
			if (!dmx and can(m - i - 1, sm2 - (9 - d)))
				maxx += char('0' + (9 - d)), sm2 -= (9 - d), dmx = 1;
		}
	if ((minn[0] == '0' or maxx[0] == '0' or sm1 or sm1))
		return puts("-1 -1"), 0;
	cout << minn, sp(), cout << maxx;
	return 0;
}
