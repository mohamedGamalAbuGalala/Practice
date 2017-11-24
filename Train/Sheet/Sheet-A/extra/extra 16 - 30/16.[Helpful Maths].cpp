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
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	vector<char> v;
	string x;
	cin >> x;
	for (int i = 0; i < sz(x); i += 2)
		v.pb(x[i]);
	sort(all(v));
	for (int i = 0; i < sz(v); ++i) {
		cout << v[i];
		if (i + 1 < sz(v))
			cout << '+';
	}
	return 0;
}
