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
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define otc(x) printf("%c", x)	//output char

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int main() { // dfil
	fl(); //TODO
	string s;
	cin >> s;
	vector<pair<char, int>> vv;
	forr(i,0,sz(s))
	{
		int jj = i + 1;
		forr(j,jj,sz(s))
			if (s[j] != s[i])
				break;
			else
				jj++;
		vv.pb( { s[i], jj - i });
		i = jj - 1;
	}
	if ((sz(vv) == 1 and vv[0].second >= 3) or vv[0].second >= 3)
		vv[0].second = 2;
	forr(i,1,sz(vv))
		if (vv[i - 1].second >= 2 and vv[i].second >= 2)
			vv[i].second = 1;
		else if (vv[i].second >= 3)
			vv[i].second = 2;
	forr(i,0,sz(vv))
		forr(j,0,vv[i].second)
			otc(vv[i].first);
	return 0;
}
