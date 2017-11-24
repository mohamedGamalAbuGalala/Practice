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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	map<string, int> mm;
	int n;
	string a;
	cin >> n;
	while (n--, cin >> a)
		mm[a]++;
	int mn = 0;
	for (auto it : mm)
		if (it.second > mn)
			a = it.first,mn = it.second;
	cout << a;
	return 0;
}
