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

struct line {
	double a, b, c;
};
// a way to represent a line

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;           // default values
	} else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

struct vec {
	double x, y;  // name: `vec' is different from STL vector
	vec(double _x, double _y) :
			x(_x), y(_y) {
	}
};

vec toVec(point a, point b) {       // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

point translate(point p, vec v) {        // translate p according to v
	return point(p.x + v.x, p.y + v.y);
}
vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
	return vec(v.x * s, v.y * s);
}               // shorter.same.longer

double dist(point p1, point p2) {                // Euclidean distance
	// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}           // return double

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));                  // translate a to c
	return dist(p, c);
}           // Euclidean distance between p and c
// struct point_i { int x, y; };    // basic raw form, minimalist mode
struct point_i {
	int x, y;     // whenever possible, work with point_i
	point_i() {
		x = y = 0;
	}                      // default constructor
	point_i(int _x, int _y) :
			x(_x), y(_y) {
	}
};
// user-defined

struct Rect {
	int h, w, d, k;
	point_i s, e;
	bool operator <(const Rect &b) const {
		return d > b.d;
	}
};
int N, L, U;
Rect nRect(Rect a) {
	if (a.k) {
		a.s.x = U - a.w, a.s.y = a.d;
	}

	return a;
}

int main() {
	file();
	int T;
	in(T);
	while (T--) {
//		int h, w, d, k;

	}
	return 0;
}
