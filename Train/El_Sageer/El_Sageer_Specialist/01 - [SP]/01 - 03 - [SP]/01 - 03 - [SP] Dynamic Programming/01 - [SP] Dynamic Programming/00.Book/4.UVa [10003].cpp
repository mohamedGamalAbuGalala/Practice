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
#define forr(i,j, n) for(int i = j;i < n;i++)
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define otc(x) printf("%c", x)	//output char
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int L, N, A[55], dp[55][55];

int cut(int l, int r) {
	if (l + 1 == r)
		return 0;
	int &ret = dp[l][r];
	if (ret == -1) {
		ret = 999999999;
		forr(i,l+1,r)
			ret = min(ret, cut(l, i) + cut(i, r) + (A[r] - A[l]));
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	while (in(L) and L and in(N)) {
		A[0] = 0, A[N + 1] = L, mem(dp, -1);
		forr(i, 1, N+1 and in(A[i]));
		ots("The minimum cutting is "), ot(cut(0, N + 1)), otc('.'), ln();
	}
	return 0;
}
