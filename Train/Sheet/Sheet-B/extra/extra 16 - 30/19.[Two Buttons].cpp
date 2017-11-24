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
int n, m, a;
int main() { // dfil
	fl(); //TODO
	cin >> n >> m;
	while (n < m)
		m % 2 ? m++ : m /= 2, a++;
	cout << a + n - m;
	return 0;
}

