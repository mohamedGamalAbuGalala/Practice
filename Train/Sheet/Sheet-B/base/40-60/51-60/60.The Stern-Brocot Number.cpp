#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ots(x) printf("%s ", x)
#define otc(x) printf("%c", x)
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
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e6 + 1e5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

vector<int> v;

void solve(int nominator, int denominator) {
	if (nominator == 1)
		return;
	v.push_back(nominator / denominator);
	solve(denominator, nominator % denominator);

}

int main() {
	file();

	int m, n;
	while (in(m), in(n)) {
		if (m == 1 && n == 1)
			break;
		v.clear();

		if (m < n) {
			v.push_back(0);
			solve(n, m);
		} else
			solve(m, n);

		v[sz(v) - 1] = v[sz(v) - 1] - 1;

		for (int i = 0; i < sz(v); i++)
			for (int j = 0; j < v[i]; j++)
				if (i % 2)
					otc('L');
				else
					otc('R');
		ln();
	}
	return 0;
}
