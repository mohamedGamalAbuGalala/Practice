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

char board[15][15];
int n, ans, t;
//bitset<30> rw, ld, rd;
int rw, ld, rd;
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
void bT(int c) {
	if (c == n and ++ans)
		return;
	for (int r = 0; r < n; r++)
		if (board[r][c]
				!= '*'&& !isOn(rw,r) and !isOn(ld,(r - c + n - 1)) and !isOn(rd,(r+c)))
			setBit(rw,r), setBit(ld, (r - c + n - 1)), setBit(rd, (r + c)), bT(
					c + 1), clearBit(rw, r), clearBit(ld, (r - c + n - 1)), clearBit(
					rd, (r + c));
}

int main() {
	file();
	while (in(n) and n) {
		ans = 0;
		for (int i = 0; i < n; ++i)
			ins(board[i]);
		bT(0);
		printf("Case %d: %d\n", ++t, ans);
	}
	return 0;
}
/*if (board[r][c] != ’*’ && !rw[r] && !ld[r - c + n - 1] && !rd[r + c]){
 rw[r] = ld[r - c + n - 1] = rd[r + c] = 1;
 bT(c + 1);
 rw[r] = ld[r - c + n - 1] = rd[r + c] = 0;
 }*/
