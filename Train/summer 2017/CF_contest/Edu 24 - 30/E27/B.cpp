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
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define in(n) scanf("%d",&n)	//scan int
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
typedef vector<int> vi;
const int OO = 1e9 + 5;
#define ot(x) printf("%d", x)	//output int

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int a, mn = OO, a0, a1, a2, a3, a4, a5, cnt = 0, aa;
	in(a), aa = a;
	forr(a0,0,10)
		forr(a1,0,10)
			forr(a2,0,10)
				forr(a3,0,10)
					forr(a4,0,10)
						forr(a5,0,10)
							if (a0 + a1 + a2 == a3 + a4 + a5) {
								cnt += a0 != a % 10, a /= 10;
								cnt += a1 != a % 10, a /= 10;
								cnt += a2 != a % 10, a /= 10;
								cnt += a3 != a % 10, a /= 10;
								cnt += a4 != a % 10, a /= 10;
								cnt += a5 != a % 10, a /= 10;
								mn = min(mn, cnt), cnt = 0, a = aa;
							}
	ot(mn);
	return 0;
}
