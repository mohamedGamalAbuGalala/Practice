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
#define forr(i, n) for(int i = 0;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, arr[105], c1 = 0, c0 = 0;
	cin >> n;
	forr(i,n)
		cin >> (arr[i]), c1 += arr[i];
	int ans = 0;
	forr(i,n)
		c0 += (!arr[i]), ans = max(ans, c0 + c1), c1 -= arr[i];
	cout << ans;
	return 0;
}
