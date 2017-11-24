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
#define otf(x) printf("%.2lf", x)// output double/float with 0.00
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
const int MN = 1e5 + 1e1;
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

char c[1001], buf[100];
int d[1001], ans, t, n, q;
double x, y, a, d1, d2;

double rad(double _) {
	return _ * PI / 180.0;
}
void check(int id) {
	switch (c[id]) {
	case 'f':
		x += d[id] * cos(a);
		y += d[id] * sin(a);
		break;
	case 'b':
		x -= d[id] * cos(a);
		y -= d[id] * sin(a);
		break;
	case 'l':
		a += rad(d[id]);
		break;
	case 'r':
		a -= rad(d[id]);
	}
}
void makePoint() {
	a = x = y = 0.0;
	for (i = 0; i < n; ++i)
		check(i);
}
int main() {
	file(); //TODO
	in(t);
	while (t-- and in(n)) {
		forr(i,0,n)
		{
			ins(buf), c[i] = buf[0], ins(buf);
			if (buf[0] == '?')
				q = i;
			else
				sscanf(buf, "%d", d + i);
		}
		if (c[q] == 'f' or c[q] == 'b') {
			d[q] = 0;
			makePoint();
			ans = round(hypot(x, y));
			d[q] = ans;
			makePoint();
			d1 = hypot(x, y);
			d[q] = -ans;
			makePoint();
			d2 = hypot(x, y);
			if (d1 > d2)
				ans *= -1;
		} else
			forr(ans,0,360)
			{
				d[q] = ans, makePoint();
				if (abs(x) < 0.01 and abs(y) < 0.01)
					break;
			}
		ot(ans), ln();
	}
	return 0;
}
