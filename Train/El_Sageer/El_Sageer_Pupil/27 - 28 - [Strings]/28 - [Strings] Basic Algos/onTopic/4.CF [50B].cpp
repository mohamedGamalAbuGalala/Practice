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
#define otl(x) printf("%lld", x)//output long long int
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;
lli f[256];
int main() { // dfil
	fl(); //TODO
	string s;
	cin >> s;
	for (int it : s)
		f[it]++;
	lli res = 0;
	for (auto it : f)
		res += (it * it);
	otl(res);
	return 0;
}
