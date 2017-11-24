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
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define forr(i,j, n) for(int i = j;i < n;i++)
#define all(v) v.begin(), v.end()

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int n, m, k, q, a, b;
string res[] { "Carrots", "Kiwis", "Grapes", "Waste" };
using lli = long long int;
set<lli> wst;
lli idx;

int main() { // dfil
	fl(); //TODO
	in(n), in(m), in(k), in(q);
	forr(i,0,k and in(a) and in(b))
		a--, b--, wst.insert(lli(a * m + b));
	forr(i,0,q and in(a) and in(b))
	{
		a--, b--, idx = lli(a * m + b);
		auto f = wst.find(idx);
		if (f == wst.end()) {
			idx -= distance(wst.begin(), wst.lower_bound(idx));
			ots(res[idx % 3].c_str()), ln();
		} else
			ots(res[3].c_str()), ln();
	}
	return 0;
}
