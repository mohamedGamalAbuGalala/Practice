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

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}

#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define cl(v,d) memset(v,d,sizeof(v))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))

const int MN = 1e4 + 5;
const int MW = 1e3 + 5;

const int OO = 1e9 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
typedef pair<lli, string> lls;

int main() {

	file();
	int n, m, a, b, c, ow[101];
	mem(ow, 0);
	in(n), in(m);
	for (int i = 0; i < m and in(a) and in(b) and in(c);
			ow[a] += c, ow[b] -= c, ++i)
		;
	lli sm = 0;
	for (int i = 1; i <= n; ++i)
		sm += ((ow[i] > 0) ? ow[i] : 0);
	otl(sm);
	return 0;
}
