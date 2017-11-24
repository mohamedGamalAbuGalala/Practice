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
const int MN = 1e6 + 1e1;
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, mx = 0;
	string x, res = "1";
	cin >> n;
	forr(i,0,n and cin>>x)
	{
		if (x == "0")
			return cout << 0, 0;
		bool don = 0;
		forr(j,'2','9'+1)
		{
			auto f = x.find(j);
			if (f != string::npos)
				res = x, don = 1;
		}
		if (x != "1") {
			auto f = x.find('0');
			if (f == string::npos)
				res = x, don = 1;
			f = x.find('1'), f = x.find('1', f + 1);
			if (f != string::npos)
				res = x, don = 1;
		}
		if (!don)
			mx += sz(x) - 1;
	}
	cout << res, res.assign(mx, '0'), cout << res;
	return 0;
}
