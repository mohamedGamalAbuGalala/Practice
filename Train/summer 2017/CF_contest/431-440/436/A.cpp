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
	int n, a[111];
	cin >> n;
	forr(i, 1, n +1 and cin>>a[i]);
	sort(a + 1, a + n + 1);
	if (a[1] == a[(n / 2)] and a[(n / 2) + 1] == a[n] and a[1] != a[n])
		cout << "YES\n" << a[1] << " " << a[n];
	else
		cout << "NO";
	return 0;
}
