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
	map<char, int> mp;
	int odc = 0;
	string a;
	cin >> a;
	for (auto ch : a)
		mp[ch]++, (mp[ch] & 1) ? odc++ : odc--;
//	cout<<odc;
	if (!odc or (odc & 1))
		puts("First");
	else
		puts("Second");
	return 0;
}
