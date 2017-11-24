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
#define otc(x) printf("%c", x)	//output char
#define inl(n) scanf("%lld",&n)	//scan long long int
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	using lli = long long int;
	lli sa = 0, sg = 0, n, ai, gi;
	inl(n);
	forr(i,0,n and inl(ai) and inl(gi))
		if (abs((sa + ai) - sg) <= 500)
			otc('A'), sa += ai;
		else
			otc('G'), sg += gi;
	return 0;
}
