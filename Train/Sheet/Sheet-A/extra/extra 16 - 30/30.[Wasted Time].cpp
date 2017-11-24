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
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

#define EPS 1e-9

struct point {
	double x, y;
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() { // dfil
	fl(); //TODO
	point lsp, p;
	const double v = 50;
	int n, k;
	double d = 0;
	cin >> n >> k >> lsp.x >> lsp.y;
	forr(i, 1 , n and cin>>p.x>>p.y)
		d += dist(p, lsp), lsp = p;
	double tpp = d / v;
	printf("%.9lf", (tpp * k));
	return 0;
}
