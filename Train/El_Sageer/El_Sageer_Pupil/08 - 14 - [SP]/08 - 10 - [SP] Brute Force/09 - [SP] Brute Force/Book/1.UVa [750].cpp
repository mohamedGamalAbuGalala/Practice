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
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e9 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int row[8], x, y, lin;

bool plac(int r, int c) {
	for (int p = 0; p < c; ++p)
		if (row[p] == r or abs(row[p] - r) == abs(p - c))
			return 0;
	return 1;
}

void bT(int c) {
	if (c == 8 and row[y] == x) {
		printf("%2d      %d", ++lin, row[0] + 1);
		for (int i = 1; i < 8; ++i)
			otc(' '), ot(row[i] + 1);
		ln();
	}
	for (int r = 0; r < 8; ++r)
		if (plac(r, c))
			row[c] = r, bT(c + 1);
}

int main() {
	file();
	int T;
	in(T);
	while (T-- and in(x) and in(y)) {
		x--, y--, mem(row, 0), lin = 0;
		puts("SOLN       COLUMN"), puts(" #      1 2 3 4 5 6 7 8"), ln();
		bT(0);
		if (T)
			ln();
	}
	return 0;
}
