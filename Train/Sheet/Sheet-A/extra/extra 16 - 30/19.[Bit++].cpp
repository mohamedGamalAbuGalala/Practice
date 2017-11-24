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
	int ans = 0, n;
	string x;
	cin >> n;
	forr(i,0,n and cin>>x)
	{
		auto f = x.find('+');
		if (f != string::npos)
			ans++;
		else
			ans--;
	}
	cout << ans;
	return 0;
}
