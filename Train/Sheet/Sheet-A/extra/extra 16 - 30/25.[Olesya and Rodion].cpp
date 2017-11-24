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
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n;
	string x, t;
	cin >> n >> t;
	if (n == 1 and t == "10")
		return puts("-1");
	x.assign(n - sz(t), '0'), t += x, cout << t;
	return 0;
}
