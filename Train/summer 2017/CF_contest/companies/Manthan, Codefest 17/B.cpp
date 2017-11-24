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
using lli = long long int;
const lli OO = 1e18 + 5;
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define inl(n) scanf("%lld",&n)	//scan long long int
#define otl(x) printf("%lld", x)//output long long int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define F first
#define S second
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
const int N = 123456;
lli n, p, q, r, L[N], R[N], a[N], ans = -5 * OO;

int main() { // dfil
	fl(); //TODO
	inl(n), inl(p), inl(q), inl(r);
	forr(i, 0, n and inl(a[i]));
	L[0] = p * a[0];
	forr(i,1,n)
		L[i] = max(L[i - 1], p * a[i]);
	R[n - 1] = r * a[n - 1];
	frr(i,n-2,0)
		R[i] = max(R[i + 1], r * a[i]);
	forr(i,0,n)
		ans = max(ans, L[i] + (q * a[i]) + R[i]);
	otl(ans);
	return 0;
}
