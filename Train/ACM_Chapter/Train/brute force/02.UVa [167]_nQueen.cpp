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
//	freopen("ot.txt", "w", stdout);
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

int board[8][8], row[8];
int ans = 0, t;
int rw, ld, rd;
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))

void bT(int c) {
	if (c == 8) {
		int sm = 0;
		for (int i = 0; i < 8; ++i)
			sm += board[i][row[i]];
		ans = max(sm, ans);
		return;
	}
	for (int r = 0; r < 8; r++)
		if (!isOn(rw, r) and !isOn(ld, (r - c + 7)) and !isOn(rd, (r + c))) {
			setBit(rw,r), setBit(ld, (r - c + 7)), setBit(rd, (r + c));
			row[c] = r;
			bT(c + 1);
			clearBit(rw, r), clearBit(ld, (r - c + 7)), clearBit(rd, (r + c));
		}
}

int main() {
	file();
	int T;
	in(T);
	while (T--) {
		ans = 0;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				in(board[i][j]);
		bT(0);
		printf("%5d\n", ans);
	}
	return 0;
}
