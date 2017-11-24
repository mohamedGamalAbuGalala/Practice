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
	string s, bb = "bear";
	int l, r, fb, bf = 0, ll = -1;
	lli ans = 0;
	cin >> s;
	for (int i = 0; i < sz(s); ++i) {
		fb = 0;
		if (s[i] == 'b') {
			fb = 1;
			for (int j = i, k = 0; j < i + 4 and fb; ++k, ++j)
				if (s[j] != bb[k])
					fb = 0;
		}
		if (fb) {
			if (bf)
				l = i + 2 - ll, r = sz(s) - (i + 3), ll = i + 2;
			else
				l = i + 1, r = sz(s) - (i + 3), ll = i + 2;
			ans += (l * r), bf++, i += 2;
		}
	}
	otl(ans);
	return 0;
}
