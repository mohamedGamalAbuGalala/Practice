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
#define ln() printf("\n")		//output new line
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int M, C, P[55][55], mm[55][222];

int shop(int mon, int g) {
	if (mon < 0)
		return -999999999;
	if (g == C)
		return M - mon;
	int &ret = mm[g][mon];
	if (ret == -1)
		forr(i,1,P[g][0]+1)
			ret = max(ret, shop(mon - P[g][i], g + 1));
	return ret;
}

int main() { // dfil
	fl(); //TODO
	int T, ans;
	in(T);
	while (T-- and in(M) and in(C)) {
		forr(i,0,C and in(P[i][0]))
			forr(j, 1, P[i][0]+1 and in(P[i][j]));
		mem(mm, -1);
		ans = shop(M, 0);
		if (ans < 0)
			puts("no solution");
		else
			ot(ans), ln();
	}
	return 0;
}
