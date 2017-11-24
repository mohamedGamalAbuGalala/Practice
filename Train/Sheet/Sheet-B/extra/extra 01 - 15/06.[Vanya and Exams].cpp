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
#define inl(n) scanf("%lld",&n)	//scan long long int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define F first
#define S second
#define min(x,y) (x<y)? x : y

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	using lli = long long int;
	typedef pair<lli, lli> ii;
	lli n, R, ci = 0, ans = 0, p;
	lli avg, av = 0;
	ii a[111111];
	inl(n), inl(R), inl(avg), avg *= n;
	forr(i, 0, n and inl(a[i].S) and inl(a[i].F))
		av += a[i].S;
	if (av >= avg)
		ans = 0;
	else {
		sort(a, a + n), ci = 0;
		while (av < avg)
			p = min((avg - av), (R - a[ci].S)), av += p, ans += p * a[ci].F, ci++;
	}
	otl(ans);
	return 0;
}
