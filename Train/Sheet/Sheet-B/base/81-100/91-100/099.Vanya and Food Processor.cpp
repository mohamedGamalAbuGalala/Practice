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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;
lli a[int(1e5) + 100];

int main() { // dfil
	fl(); //TODO
	lli n, h, k, ans = 0;
	inl(n), inl(h), inl(k);
	forr(i, 0, n and inl(a[i]));
	forr(i,0,n)
	{
		ans += a[i] / k;
		if (i < n - 1 and a[i + 1] + (a[i] % k) <= h)
			a[i + 1] += a[i] % k;
		else
			ans += (a[i] % k > 0);
	}
	otl(ans);
	return 0;
}
