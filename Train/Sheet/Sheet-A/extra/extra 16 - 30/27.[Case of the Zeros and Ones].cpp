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
#define all(v) v.begin(), v.end()

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	string a;
	int n, c0, c1;
	cin >> n >> a, c0 = c1 = 0;
	for (auto it : a)
		(it == '1') ? c1++ : c0++;
	cout << n - (min(c0, c1) * 2);
	return 0;
}
