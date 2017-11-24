#include <bits/stdc++.h>
using namespace std;

// input handle
#define in(n) scanf("%d",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x);
#define ln() printf("\n");
#define otl(x) printf("%lld", x);
#define otf(x) printf("%.2lf", x);

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

const int OO = 1e9;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
typedef pair<lli, string> lls;

int main() {
	file();
	lli w, h, cnt = 0, x, y;
	inl(w), inl(h);
	for (int i = 2; i <= w; i += 2)
		for (int j = 2; j <= h; cnt += (x * y), j += 2)
			x = w - i + 1, y = h - j + 1;
	otl(cnt);
	return 0;
}
