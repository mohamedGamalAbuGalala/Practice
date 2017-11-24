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
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

using lli = long long int;
lli mod = 1000000007;

int main() { // dfil
	fl(); //TODO
	int n, m;
	string a[112];
	lli ans = 1;
	cin >> n >> m;
	forr(i, 0, n and cin>>a[i]);
	forr(k,0,m)
	{
		set<char> se;
		forr(i,0, n)
			se.insert(a[i][k]);
		ans *= lli(se.size());
		ans %= mod;
	}
	cout << ans;
	return 0;
}
