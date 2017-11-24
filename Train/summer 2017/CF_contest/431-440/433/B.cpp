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
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	using lli = long long int;
	lli n, k;
	cin >> n >> k;
	if (k == n or !k)
		return cout << 0 << " " << 0, 0;
	else
		cout << 1;
	cout << " ";
	if ((k * 2) + k <= n)
		cout << (k * 2);
	else
		cout << n - k;
	return 0;
}
