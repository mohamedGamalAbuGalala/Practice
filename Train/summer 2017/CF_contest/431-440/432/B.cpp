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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;
struct point {
	lli x, y;
};
lli dist(point p1, point p2) {
	return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() { // dfil
	fl(); //TODO
	point a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	if (dist(a, b) == dist(b, c)
			and (a.x - c.x) * (b.y - c.y) != (b.x - c.x) * (a.y - c.y))
		puts("Yes");
	else
		puts("No");
	return 0;
}
