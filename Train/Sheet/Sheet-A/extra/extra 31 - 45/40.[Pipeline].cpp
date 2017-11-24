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

int o, m;
long long n, k = 1;

int main() { // dfil
	fl(); //TODO
	cin>>n>>m;
	while (m != o and k < n)
		o++, k += m - o;
	if (k >= n)
		cout << o;
	else
		cout << -1;
	return 0;
}
