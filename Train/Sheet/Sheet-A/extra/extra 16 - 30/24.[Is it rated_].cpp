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

int main() { // dfil
	fl(); //TODO
	int n, a, b, la, lb;
	bool ord = 1;
	cin >> n >> la >> lb, n--;
	if (la != lb)
		return puts("rated");
	while (n-- and cin >> a >> b) {
		ord &= la >= a and lb >= b;
		if (a != b)
			return puts("rated");
		la = a, lb = b;
	}
	if (ord)
		puts("maybe");
	else
		puts("unrated");
	return 0;
}
