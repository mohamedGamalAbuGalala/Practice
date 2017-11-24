#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x)
#define sp() printf(" ")
#define ots(x) printf("%s", x)
#define otc(x) printf("%c", x)
#define ln() printf("\n")
#define otl(x) printf("%lld", x)
#define otf(x) printf("%.14lf", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(s) ((int)strlen(s))
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
const int MN = 2e6 + 1e2;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int main() {
	file();
	int abcde, fghij, used, tmp, N;
	in(N);
	while (N) {
		bool f = 0;
		for (abcde = 1234; abcde <= 98765 / N; ++abcde) {
			fghij = abcde * N, used = (abcde < 10000), tmp = abcde;
			while (tmp)
				used |= (1 << (tmp % 10)), tmp /= 10;
			tmp = fghij;
			while (tmp)
				used |= (1 << (tmp % 10)), tmp /= 10;
			if (used == (1 << 10) - 1)
				f = 1, printf("%0.5d / %0.5d = %d\n", fghij, abcde, N);
		}
		if (!f)
			ots("There are no solutions for "), ot(N), otc('.'), ln();
		in(N);
		if (N)
			ln();
	}
	return 0;
}
