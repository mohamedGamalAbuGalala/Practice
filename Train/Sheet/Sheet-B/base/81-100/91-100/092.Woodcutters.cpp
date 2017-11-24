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
#define inl(n) scanf("%lld",&n)	//scan long long int
#define otl(x) printf("%lld", x)//output long long int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define F first
#define S second

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
const int MN = 1e5 + 1e1;
using lli = long long int;
typedef pair<lli, lli> ii;

ii a[MN];

int main() { // dfil
	fl(); //TODO
	lli l, ans = 2, n;
	inl(n);
	forr(i, 0, n and inl(a[i].F) and inl(a[i].S));
	l = a[0].F + 1;
	forr(i,1,n-1)
	{
		if (a[i].F - a[i].S >= l)
			l = a[i].F + 1, ans++;
		else if (a[i].F + a[i].S + a[i + 1].S < a[i + 1].F)
			l = a[i].F + a[i].S + 1, ans++;
		else if (a[i].F + a[i].S < a[i + 1].F)
			l = a[i + 1].F + 1, ans++;
		else
			l = a[i].F + 1;
	}
	if (n == 1)
		ans = 1;
	otl(ans);
	return 0;
}
