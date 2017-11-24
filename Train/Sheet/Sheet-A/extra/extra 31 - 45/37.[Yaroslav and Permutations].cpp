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
#define forr(i,j, n) for(i = j;i < n;i++)
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO

	int n, a[1001] = { 0 }, i, t;
	cin >> n;
	forr(i,0,n and cin>>t)
	{
		a[t]++;
		if (a[t] > (n + 1) / 2)
			break;
	}

	puts(i == n ? "YES" : "NO");

	return 0;
}
