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
	int dst[350][350][2], s, d, T, n, m, u, v, t, c, OO = 912345678, q;
	in(T);
	while (T-- and in(n) and in(m)) {
		n++;
		forr(i,1,n)
		{
			forr(j,1,n)
				dst[i][j][0] = dst[i][j][1] = OO;
			dst[i][i][0] = dst[i][i][1] = 0;
		}
		forr(i,0,m and in(u) and in(v) and in(t) and in(c))
		{
			if (dst[u][v][0] > t)
				dst[u][v][0] = t, dst[v][u][1] = c, dst[v][u][0] = t, dst[u][v][1] =
						c;
			else if (dst[u][v][0] == t)
				dst[v][u][1] = dst[u][v][1] = min(dst[v][u][1], c);
		}

		forr(k,1,n)
			forr(i,1,n)
				forr(j,1,n)
					if (dst[i][k][0] < OO and dst[k][j][0] < OO) {
						if (dst[i][j][0] > dst[i][k][0] + dst[k][j][0])
							dst[i][j][0] = (dst[i][k][0] + dst[k][j][0]), dst[i][j][1] =
									(dst[i][k][1] + dst[k][j][1]);
						else if (dst[i][j][0] == dst[i][k][0] + dst[k][j][0])
							dst[i][j][1] = min(dst[i][j][1],
									(dst[i][k][1] + dst[k][j][1]));
					}

		in(q);
		while (q--) {
			in(s), in(d);
			if (dst[s][d][0] != OO)
				printf("Distance and time to reach destination is %d & %d.\n",
						dst[s][d][1], dst[s][d][0]);
			else
				puts("No Path.");
		}
		if (T)
			puts("");
	}
	return 0;
}
