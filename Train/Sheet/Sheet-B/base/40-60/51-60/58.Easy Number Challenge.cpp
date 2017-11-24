#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ots(x) printf("%s ", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(ss) ((int)strlen(s))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
// constants
const int MN = 1e6 + 1e5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

const lli MOD = 1073741824;
const lli lim = 100 * 100 * 100 + 100;
lli dd[lim];

void clc() {
	for (int i = 1; i < lim; ++i)
		for (int j = i; j < lim; j += i)
			dd[j]++;
}

int main() {
	file();
	int a, b, c;
	in(a), in(b), in(c), clc();
	lli ans = 0;
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j)
			for (int k = 1; k <= c; ++k)
				ans += dd[i * j * k];
	otl(ans % MOD);
	return 0;
}
