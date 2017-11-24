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
	int n, m, idx;
	bool a[1001] { 0 };
	cin >> n >> m;
	string d, fl;
	forr(i,0,m and cin>>fl>>fl>>d>>fl>>idx)
	{
		if (d == "left")
			forr(j,idx,n+1)
				a[j] = 1;
		else
			frr(j,idx,1)
				a[j] = 1;
	}
	int res = 0;
	forr(i,1,n+1)
		res += (!a[i]);
	cout << ((!res) ? -1 : res);
	return 0;
}
