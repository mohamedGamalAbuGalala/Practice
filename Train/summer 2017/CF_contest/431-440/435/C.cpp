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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO

	const int pw1 = (1 << 17);
	const int pw2 = (1 << 18);

	int n, x;
	cin >> n >> x;
	if (n == 1)
		cout << "YES\n" << x << "\n";
	else if (n == 2 and x == 0)
		cout << "NO\n";
	else if (n == 2)
		cout << "YES\n0 " << x << "\n";
	else {
		int ans = 0;
		cout << "YES\n";
		forr(i,1,n-2)
			cout << i << " ", ans ^= i;
		if (ans == x)
			cout << pw1 + pw2 << " " << pw1 << " " << pw2 << "\n";
		else
			cout << pw1 << " " << ((pw1 ^ x) ^ ans) << " 0 \n";
	}
	return 0;
}
