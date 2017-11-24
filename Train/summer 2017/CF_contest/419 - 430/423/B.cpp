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
	int n, m, si = OO, sj = OO, ei = -1, ej = -1, b = 0, ans = 0;
	char ar[201][201];
	in(n), in(m);
	for (int i = 0; i < n and cin >> ar[i]; ++i)
		;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (ar[i][j] == 'B')
				b++, si = min(i, si), ei = max(i, ei), sj = min(j, sj), ej =
						max(j, ej);

	if (!b)
		return ot(1), 0;
	if (ei - si >= m or ej - sj >= n)
		return ot(-1), 0;
	ans = max(ei - si + 1, ej - sj + 1);
	ot(ans * ans - b);
	return 0;
}
