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
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int f[200010][2];

int main() { // dfil
	fl(); //TODO
	string a, b;
	cin >> a >> b;
	forr(i,1,sz(b)+1)
	{
		forr(j,0,2)
			f[i][j] = f[i - 1][j];
		++f[i][b[i - 1] - '0'];
	}
	using lli = long long int;
	lli res = 0;
	forr(i,0,sz(a))
	{
		int c = a[i] - '0';
		forr(j,0,2)
			res += abs(c - j) * (f[sz(b) - sz(a) + i + 1][j] - f[i][j]);
	}
	cout << res;
	return 0;
}
