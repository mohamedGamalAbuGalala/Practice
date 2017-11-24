#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
// constants
const int MN = 1e5 + 5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<lli, string> lls;

int main() {
	file();
	int n, a, b, aa = 0, don = 0, x;
	lli ans = 0;
	in(n), in(a), in(b);
	for (int i = 0; i < n and in(x); don = 0, ++i) {
		if (x == 2 and b)
			don = 1, b--;
		else if (x == 1 and a)
			don = 1, a--;
		else if (x == 1 and !a and b)
			don = 1, b--, aa++;
		else if (x == 1 and !a and !b and aa)
			don = 1, aa--;
		if (!don)
			ans += x;
	}
	ot(ans);
	return 0;
}
