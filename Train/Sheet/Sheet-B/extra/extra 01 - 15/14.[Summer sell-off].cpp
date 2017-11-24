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
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define inl(n) scanf("%lld",&n)	//scan long long int
#define otl(x) printf("%lld", x)//output long long int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define F second.first
#define S second.second
#define FF first

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, f;
	using lli = long long int;
	typedef pair<lli, lli> ii;
	typedef pair<lli, ii> iii;
	iii a[111111];
	in(n), in(f);
	forr(i,0,n and inl(a[i].F) and inl(a[i].S))
	{

		if (a[i].S > a[i].F)
			a[i].FF = (min(2 * a[i].F, a[i].S) - a[i].F);
		else
			a[i].FF = 0;
		if (!a[i].F)
			i--, n--;
	}
	sort(a, a + n, greater<iii>());
	lli ans = 0;
	forr(i,0,n)
		if (f)
			ans += min(a[i].F * 2, a[i].S), f--;
		else
			ans += min(a[i].F, a[i].S);
	otl(ans);
	return 0;
}

