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
	int n;
	cin >> n;
	int psq = sqrt(n);
	int df = n - (psq * psq);
	if (!df)
		cout << (4 * psq);
	else if (df <= psq)
		cout << (4 * psq) + 2;
	else
		cout << (4 * psq) + 4;
	return 0;
}
