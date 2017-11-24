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
using lli = long long int;
#define F first
#define S second
#define in(n) scanf("%d",&n)	//scan int
#define inl(n) scanf("%lld",&n)	//scan long long int
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n;
	lli x1, x2, m, c;
	in(n);
	inl(x1), inl(x2);
	vector<pair<lli, lli>> ar(n);
	forr(i,0, n and inl(m) and inl(c))
		ar[i].F = m * x1 + c, ar[i].S = m * x2 + c;
	sort(all(ar));
	forr(i,1,n)
		if (ar[i].S < ar[i - 1].S)
			return puts("YES"), 0;
	puts("NO");
	return 0;
}
