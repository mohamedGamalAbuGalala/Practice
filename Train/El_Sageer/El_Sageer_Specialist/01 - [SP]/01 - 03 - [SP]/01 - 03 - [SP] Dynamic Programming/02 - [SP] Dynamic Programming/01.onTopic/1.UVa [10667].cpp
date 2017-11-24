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
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

bool ch(int r1, int c1, int r2, int c2, int Ir1, int Ic1, int Ir2, int Ic2) {
	return ((r1 < Ir1 and r2 < Ir1) or (r1 > Ir2 and r2 > Ir2))
			or ((c1 < Ic1 and c2 < Ic1) or (c1 > Ic2 and c2 > Ic1));
	// on top of invalid or down of invalid or on left of invalid or on right of invalid.
}

#define r1 first.first
#define c1 first.second
#define r2 second.first
#define c2 second.second

int main() { // dfil
	fl(); //TODO
	int T, S, B, maxSubRect, subRect;
	int a[101][101];
	typedef pair<int, int> ii;
	typedef pair<ii, ii> iiii;
	iiii b[101];
	in(T);
	forr(i,0,101)
		forr(j,0,101)
		{
			a[i][j] = 1;
			if (i)
				a[i][j] += a[i - 1][j];
			if (j)
				a[i][j] += a[i][j - 1];
			if (i and j)
				a[i][j] -= a[i - 1][j - 1];
		}

	while (T-- and in(S) and in(B)) {

		forr(i,0,B and in(b[i].r1) and in(b[i].c1) and in(b[i].r2) and in(b[i].c2))
			b[i].r1--, b[i].c1--, b[i].r2--, b[i].c2--;

		maxSubRect = 0;
		forr(i,0,S)
			forr(j,0,S)
				forr(k,i,S)
					forr(l,j,S)
					{
						bool val = 1;
						forr(q,0,B and val)
							if (!ch(i, j, k, l, b[q].r1, b[q].c1, b[q].r2,
									b[q].c2))
								val = 0;
						if (!val)
							continue;
						subRect = a[k][l];
						if (i)
							subRect -= a[i - 1][l];
						if (j)
							subRect -= a[k][j - 1];
						if (i and j)
							subRect += a[i - 1][j - 1];
						maxSubRect = max(maxSubRect, subRect);
					}
		printf("%d\n", maxSubRect);
	}
	return 0;
}
/*

 forr(i,0,S)
 forr(j,0,S)
 if (j > 0 and a[i][j])
 a[i][j] += a[i][j - 1];

 maxSubRect = -1;
 forr(l,0,S)
 forr(r,l,S)
 {
 subRect = 0;
 forr(row,0,S)
 {
 if (l > 0)
 subRect += a[row][r] - a[row][l - 1];
 else
 subRect += a[row][r];

 if (subRect < 0)
 subRect = 0;
 maxSubRect = max(maxSubRect, subRect);
 }
 }

 */
