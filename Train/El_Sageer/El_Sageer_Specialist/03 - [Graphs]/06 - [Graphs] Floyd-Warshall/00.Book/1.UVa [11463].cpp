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
#define in(n) scanf("%d",&n)	//scan int

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int main() { // dfil
	fl(); //TODO
	int dst[112][112], s, d, T, n, m, u, v, OO = 912345678, tt = 0;
	in(T);
	while (T-- and in(n) and in(m)) {
		forr(i,0,n)
		{
			forr(j,0,n)
				dst[i][j] = OO;
			dst[i][i] = 0;
		}
		forr(i,0,m and in(u) and in(v))
			dst[u][v] = 1, dst[v][u] = 1;
		forr(k,0,n)
			forr(i,0,n)
				forr(j,0,n)
					if (dst[i][k] < OO and dst[k][j] < OO)
						dst[i][j] = min(dst[i][j], (dst[i][k] + dst[k][j]));
		in(s), in(d);
		int mx = 0;
		forr(i,0,n)
			mx = max(mx, dst[s][i] + dst[i][d]);
		printf("Case %d: %d\n", ++tt, mx);
	}
	return 0;
}
