//	using vv = vector<vector<int>>;
//
//	vv v(100, vector<int>(100, 0));
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
#define otf(x) printf("%.12lf", x)// output double/float with 0.00
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
const int MN = 1e6 + 1e1;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
const lli MOD = 1000000009;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 }, i, j, k;
#define ff first
#define ss second
#define WH -1
#define BL 1
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)

int Kx, Ky, Cx, Cy, Tx, Ty, n, x, y;
double pre[MN], suff[MN], add[MN], all, ad, ans;
double dist(int x, int y, int a, int b) {
	return sqrt((lli) (x - a) * (x - a) + (lli) (y - b) * (y - b));
}
int main() {
	file(); //TODO
	in(Kx), in(Ky), in(Cx), in(Cy), in(Tx), in(Ty), in(n);
	forr(i, 1, n+1 and in(x)and in(y))
	{
		ad = dist(Tx, Ty, x, y), all += ad * 2;
		suff[i] = pre[i] = dist(Cx, Cy, x, y) - ad;
		add[i] = dist(Kx, Ky, x, y) - ad;
	}
	pre[0] = suff[n + 1] = 1e18 + 5;
	forr(i, 1, n+1)
		pre[i] = min(pre[i - 1], pre[i]);
	frr(i, n, 1)
		suff[i] = min(suff[i + 1], suff[i]);
	ans = suff[1] + all;
	forr(i, 1, n+1)
		ans = min(ans, all + min(0.0, min(pre[i - 1], suff[i + 1])) + add[i]);
	otf(ans);
	return 0;
}
