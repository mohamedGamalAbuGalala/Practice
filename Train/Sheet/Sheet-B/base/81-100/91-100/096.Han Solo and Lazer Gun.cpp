#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define F first
#define S second
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define inf(n) scanf("%lf",&n)	//scan double/float

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

#define EPS 1e-4

struct point {
	double x, y;
};

struct line {
	double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	} else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

int main() { // dfil
	fl(); //TODO
	point s, a;
	line l;
	using iii = pair<double,pair<double,double>>;
	iii p;
	map<iii, int> mp;
	int n;
	in(n), inf(s.x), inf(s.y);
	while (n-- and inf(a.x) and inf(a.y))
		pointsToLine(s, a, l), p.F = l.a, p.S.F = l.b, p.S.S = l.c, mp[p]++;
	ot(sz(mp));
	return 0;
}
