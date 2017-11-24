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

const int MN = 1e5 + 5;
const int MW = 1e3 + 5;

const int OO = 1e9 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
typedef pair<lli, string> lls;

int main() {
	file();
	int n, ar[MN], k, sm = 0, i, l = -1, f = 0;
	in(n), in(k);
	for (i = 0; i < n and in(ar[i]); ++i) {
		if (ar[i] < 0 and k)
			ar[i] *= -1, k--;
		else if (!f and i > 0) {
			if (ar[i - 1] < ar[i])
				l = i - 1, sm -= ar[i - 1], k++, ar[i - 1] *= -1;
			else
				l = i, sm -= ar[i];
			f = 1;
		} else if (!f and i == 0)
			l = i, sm -= ar[i], f = 1;
		sm += ar[i];
	}
	if (l == -1)
		sm -= ar[n - 1], k++, ar[n - 1] *= -1, l = n - 1;
	sm += ar[l] = ((k & 1) ? ar[l] * -1 : ar[l]);
	ot(sm);
	return 0;
}
