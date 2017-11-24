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
#define F first
#define h second
#define l F.F
#define r F.h
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define  max(x,y) x>y?x:y

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int mxH[10005];

int main() { // dfil
	fl(); //TODO
	int mxe = 0, cH, st, h, en;
	while (cin >> st >> h >> en) {
		if (mxe < en)
			mxe = en;
		forr(i,st,en)
			mxH[i] = max(mxH[i], h);
	}
	cH = mxH[1], cout << "1 " << cH;

	forr(i,2,mxe)
		if (cH != mxH[i])
			cout << ' ' << i << ' ' << mxH[i], cH = mxH[i];
	cout << ' ' << mxe << " 0\n";
	return 0;
}
