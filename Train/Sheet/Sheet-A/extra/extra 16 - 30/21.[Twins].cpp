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
	int n, a[105], sm = 0, ysm = 0, ans = 0, i = 0;
	cin >> n;
	forr(i, 0, n and cin>>a[i])
		sm += a[i];
	sort(a, a + n, greater<int>());
	while (ysm <= sm)
		ysm += a[i], sm -= a[i], ans++, i++;
	cout << ans;
	return 0;
}
