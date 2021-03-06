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
int dy[] = { 0, 0, -1, 1 }, i, j;
#define ff first
#define ss second
#define WH -1
#define BL 1
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)

struct Point {
	int x, y;
};

double dist(Point a, Point b) {
	return sqrt((double) (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp(const Point &a, const Point &b) {
	return b.x < a.x;
}

int main() {
	file(); //TODO
	int T, N, mx;
	double dst;
	in(T);
	vector<Point> pp;
	Point point;
	while (T-- and in(N)) {
		pp.clear(), mx = 0, dst = 0;
		for (int i = 1; i <= N and in(point.x) and in(point.y); ++i)
			pp.push_back(point);
		sort(all(pp), cmp);
		for (int i = 1; i < sz(pp); ++i)
			if (pp[i].y > mx) {
				dst += dist(pp[i], pp[i - 1]) * (pp[i].y - mx)
						/ (pp[i].y - pp[i - 1].y);
				mx = pp[i].y;
			}
		otf(dst), ln();
	}
	return 0;
}
