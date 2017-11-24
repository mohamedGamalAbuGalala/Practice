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
	int T, N, P, X;
	cin >> T;
	while (T-- and cin >> N >> P) {
		int ans = 0, a[N + 1] { 0 };
		forr(i,0,P and cin>>X)
			for (int j = X; j <= N; j += X)
				if ((j - 1) % 7 < 5)
					a[j - 1] = 1;
		forr(i,0,N)
			ans += a[i];
		cout << ans << "\n";
	}
	return 0;
}
