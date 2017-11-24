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

lli ar[MN], v[MN], f[MN], l[MN], n, ans = 0, i;

int main() {
	file();
	inl(n), mem(v, -1), mem(f, -1), mem(l, -1);
	for (i = 0; i < n and inl(ar[i]); ++i) {
		if (f[ar[i]] == -1)
			f[ar[i]] = i;
		else if (l[ar[i]] == -1)
			l[ar[i]] = i;
	}
	for (i = 0; i < n; ++i) {
		if (v[ar[i]] == -2)
			continue;
		if (v[ar[i]] == -1) {
			ans++, v[ar[i]] = 0;
			if (l[ar[i]] < n and l[ar[i]] > 0)
				v[ar[i]] = l[ar[i]] - f[ar[i]];
		} else if (ar[i - v[ar[i]]] != ar[i])
			v[ar[i]] = -2, ans--;
	}
	otl(ans), ln();
	for (i = 1; i < MN; ++i)
		if (v[i] >= 0)
			otl(i), otl(v[i]), ln();
	return 0;
}
