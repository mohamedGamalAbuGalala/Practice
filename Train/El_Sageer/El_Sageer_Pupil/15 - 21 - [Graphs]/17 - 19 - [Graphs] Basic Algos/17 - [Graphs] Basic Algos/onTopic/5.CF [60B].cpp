#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")		//scan new line
#define in(n) scanf("%d",&n)	//scan int
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c ",&n)	//scan char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define inl(n) scanf("%lld",&n)	//scan long long int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define otc(x) printf("%c", x)	//output char
#define ln() printf("\n")		//output new line
#define otl(x) printf("%lld", x)//output long long int
#define otf(x) printf("%.9lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define max3(a,b,c) max(a , max(b , c))
#define min3(a,b,c) min(a , min(b , c))
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
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

//#define f first
//#define s second

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };
int df[] = { 1, -1 };

int K, N, M, vs, xx, yy;
char g[11][11][11];

void dfs(int f, int r, int c) {
	if (f < 0 or r < 0 or c < 0 or f >= K or r >= N or c >= M
			or g[f][r][c] != '.')
		return;
	vs++, g[f][r][c] = 'W';
	for (int i = 0; i < 4; ++i)
		dfs(f, r + dr[i], c + dc[i]);
	for (int i = 0; i < 2; ++i)
		dfs(f + df[i], r, c);
}

int main() {
	file(); // TODO
	in(K), in(N), in(M);
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < N and cin >> g[i][j]; ++j)
			;
	cin >> xx >> yy;
	dfs(0, xx - 1, yy - 1), ot(vs);
	return 0;
}
