#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ots(x) printf("%s ", x)
#define otc(x) printf("%c", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(ss) ((int)strlen(s))
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
const int MN = 1e6 + 1e5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
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

bool areParallel(line l1, line l2) {       // check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {           // also check coefficient c
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2))
		return false;            // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS)
		p.y = -(l1.a * p.x + l1.c);
	else
		p.y = -(l2.a * p.x + l2.c);
	return true;
}

int main() {
	file();

	int tt;
	in(tt);
	puts("INTERSECTING LINES OUTPUT");
	while (tt--) {
		line l1, l2;
		point p1, p2, p3, p4;
		inf(p1.x), inf(p1.y), inf(p2.x), inf(p2.y), inf(p3.x), inf(p3.y), inf(
				p4.x), inf(p4.y);

		pointsToLine(p1, p2, l1);
		pointsToLine(p3, p4, l2);

		if (areSame(l1, l2))
			puts("LINE");
		else if (areParallel(l1, l2))
			puts("NONE");
		else {
			point xxx;
			areIntersect(l1, l2, xxx); // yes, l1 (P[0]-P[1]) and l2 (P[0]-P[2]) are intersect at (2.0, 2.0)
			printf("POINT %.2lf %.2lf\n", xxx.x, xxx.y);
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
