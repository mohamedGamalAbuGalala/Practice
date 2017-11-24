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
#define otf(x) printf("%.4lf", x)// output double/float with 0.00
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

struct point {
	double x, y;   // only used if more precision is needed
	point() {
		x = y = 0.0;
	}                      // default constructor
	point(double _x, double _y) :
			x(_x), y(_y) {
	}        // user-defined
	bool operator <(point other) const { // override less than operator
		if (fabs(x - other.x) > EPS)                 // useful for sorting
			return x < other.x;          // first criteria , by x-coordinate
		return y < other.y;
	}          // second criteria, by y-coordinate
	// use EPS (1e-9) when testing equality of two floating points
	bool operator ==(point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

struct vec {
	double x, y;  // name: `vec' is different from STL vector
};

point translate(point p, vec v) {        // translate p according to v
	return point(p.x + v.x, p.y + v.y);
}

double dist(point p1, point p2) {                // Euclidean distance
	// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}           // return double
vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
	return vec { v.x * s, v.y * s };
}               // shorter.same.longer

int main() {
	file(); //TODO
	string lin, dir;
	int tt = 0;
	double sqrt2 = 1.0 / sqrt(2), stp;
	map<string, vec> mp;
	point pos;
	vec to;
	mp["N"] = vec { 0, 1 }, mp["E"] = vec { 1, 0 };
	mp["S"] = vec { 0, -1 }, mp["W"] = vec { -1, 0 };
	mp["NE"] = vec { sqrt2, sqrt2 }, mp["NW"] = vec { -sqrt2, sqrt2 };
	mp["SW"] = vec { -sqrt2, -sqrt2 }, mp["SE"] = vec { sqrt2, -sqrt2 };
	while (cin >> lin and lin != "END") {
		pos = point(0, 0), stp = 0;
		for (auto ch : lin)
			if (ch >= '0' and ch <= '9')
				stp *= 10, stp += (ch - '0');
			else if (isalpha(ch))
				dir += ch;
			else
				to = scale(mp[dir], stp), pos = translate(pos, to), dir = "", stp =
						0;
		printf("Map #%d\n", ++tt);
		printf("The treasure is located at (%.3lf,%.3lf).\n", pos.x, pos.y);
		printf("The distance to the treasure is %.3lf.\n\n",
				dist(point(), pos));
	}
	return 0;
}
