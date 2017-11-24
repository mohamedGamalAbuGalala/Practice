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
	int n, p, nn;
	cin >> n, nn = n;
	bitset<105> bs;
	bs.set(), cin >> p;
	while (p-- and cin >> n)
		bs[n - 1] = 0;
	cin >> p;
	while (p-- and cin >> n)
		bs[n - 1] = 0;
	if ((int) bs.size() - (int) bs.count() == nn)
		puts("I become the guy.");
	else
		puts("Oh, my keyboard!");
	return 0;
}
