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
typedef vector<pair<int, int>> vii;
const int OO = 1e9 + 5;
#define ot(x) printf("%d", x)	//output int

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int n, l, r, cnt = 0;
	vii v;
	in(n);
	forr(i,0,n and in(l) and in(r))
		v.pb( { l, 1 }), v.pb( { r + 1, 0 });
	sort(all(v));
	for (auto vv : v) {
		if (vv.second)
			cnt++;
		else
			cnt--;
		if (cnt >= 3)
			return puts("NO"), 0;
	}
	puts("YES");
	return 0;
}
