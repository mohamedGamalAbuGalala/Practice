#include <bits/stdc++.h>
using namespace std;

// input handle
#define in(n) scanf("%d",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x);
#define ln() printf("\n");
#define otl(x) printf("%lld ", x);
#define otf(x) printf("%.2lf ", x);

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

const int MN = 1e3 + 5;
const int MW = 1e3 + 5;

const int OO = 1e9 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
typedef pair<lli, string> lls;

int main() {
	file();
	lli n, mn = OO, mx = -1, cmn = 0, cmx = 0, x;
	inl(n);
	for (int i = 0; i < n and inl(x); ++i) {
		if (x == mx)
			cmx++;
		if (x == mn)
			cmn++;
		if (x > mx)
			mx = x, cmx = 1;
		if (x < mn)
			mn = x, cmn = 1;
	}
	otl(mx - mn);
	if (mn != mx) {
		otl(cmn * cmx);
	} else
		otl((cmn * (cmn - 1)) / 2);
	return 0;
}
