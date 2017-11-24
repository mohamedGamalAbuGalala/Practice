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

#define PI acos(-1.0)

int main() { // dfil
	fl(); //TODO
	double d, h, v, e;
	cin >> d >> h >> v >> e;
	if (!(e * PI * d * d / 4 >= v))
		printf("YES\n%.9lf", h / (((4 * v) / (PI * pow(d, 2))) - e));
	else
		puts("NO");
	return 0;
}
