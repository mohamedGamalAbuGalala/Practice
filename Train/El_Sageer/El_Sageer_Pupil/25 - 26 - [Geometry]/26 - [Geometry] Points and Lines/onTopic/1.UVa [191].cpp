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

struct Point {
	double x, y;
};
struct Segment {
	Point s, t;
};
int inL(double a, double b, double c) {
	return c >= a and c <= b;
}
int onLine(Segment& a, Point& c) {
	static double minx, maxx, miny, maxy;
	minx = min(a.s.x, a.t.x), maxx = max(a.s.x, a.t.x);
	miny = min(a.s.y, a.t.y), maxy = max(a.s.y, a.t.y);
	if (inL(minx, maxx, c.x) != 0 and inL(miny, maxy, c.y) != 0)
		if ((a.s.x - a.t.x) * (c.y - a.s.y) == (a.s.y - a.t.y) * (c.x - a.s.x))
			return 1;
	return 0;
}
double cross(Point &o, Point &a, Point &b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
int intersection(Segment& a, Segment& b) {
	if (onLine(a, b.s) or onLine(a, b.t) or onLine(b, a.s) or onLine(b, a.t))
		return 1;
	if (cross(a.s, a.t, b.s) * cross(a.s, a.t, b.t) < 0
			and cross(a.t, a.s, b.s) * cross(a.t, a.s, b.t) < 0
			and cross(b.s, b.t, a.s) * cross(b.s, b.t, a.t) < 0
			and cross(b.t, b.s, a.s) * cross(b.t, b.s, a.t) < 0)
		return 1;
	return 0;
}

int main() {
	file(); //TODO
	int t;
	Segment line, edge;
	double xl, yt, xr, yb;
	scanf("%d", &t);
	while (t-- and inf(line.s.x) and inf(line.s.y) and inf(line.t.x)
			and inf(line.t.y) and inf(xl) and inf(yt) and inf(xr) and inf(yb)) {
		if (xl > xr)
			swap(xl, xr);
		if (yt < yb)
			swap(yt, yb);
		if (inL(xl, xr, line.s.x) and inL(yb, yt, line.s.y))
			puts("T");
		else if (inL(xl, xr, line.t.x) and inL(yb, yt, line.t.y))
			puts("T");
		else {
			bool flag = 0;
			edge.s.x = xl, edge.s.y = yt, edge.t.x = xl, edge.t.y = yb;
			flag |= intersection(edge, line);
			edge.s.x = xr, edge.s.y = yt, edge.t.x = xr, edge.t.y = yb;
			flag |= intersection(edge, line);
			edge.s.x = xl, edge.s.y = yb, edge.t.x = xr, edge.t.y = yb;
			flag |= intersection(edge, line);
			edge.s.x = xl, edge.s.y = yt, edge.t.x = xr, edge.t.y = yt;
			flag |= intersection(edge, line);
			if (flag)
				puts("T");
			else
				puts("F");
		}
	}
	return 0;
}
