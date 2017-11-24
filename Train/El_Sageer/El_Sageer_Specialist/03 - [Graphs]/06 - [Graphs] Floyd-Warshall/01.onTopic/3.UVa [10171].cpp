#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define otc(x) printf("%c", x)	//output char
#define forr(i,j, n) for(int i = j;i < n;i++)
#define inc(n) scanf("%c ",&n)	//scan char

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int main() { // dfil
	fl(); //TODO
	int n;
	while (in(n) and n) {
		int y[30][30], o[30][30], c, OO = 912345678;
		char u, v, ag, dir, s, d;
		forr(i,0,30)
		{
			forr(j,0,30)
				y[i][j] = o[i][j] = OO;
			y[i][i] = o[i][i] = 0;
		}
		forr(i,0, n and getchar() and inc(ag) and inc(dir) and inc(u) and inc(v) and in(c))
		{
			int uu = u - 'A', vv = v - 'A';
			if (uu != vv) {
				if (ag == 'Y') {
					if (dir == 'U')
						y[uu][vv] = c;
					else
						y[uu][vv] = y[vv][uu] = c;
				} else {
					if (dir == 'U')
						o[uu][vv] = c;
					else
						o[uu][vv] = o[vv][uu] = c;
				}
			}
		}
		forr(k,0,30)
			forr(i,0,30)
				forr(j,0,30)
				{
					if (y[i][k] < OO and y[k][j] < OO)
						y[i][j] = min(y[i][j], (y[i][k] + y[k][j]));
					if (o[i][k] < OO and o[k][j] < OO)
						o[i][j] = min(o[i][j], (o[i][k] + o[k][j]));
				}
		int mn = OO;
		getchar(), inc(s), inc(d);
		int so = s - 'A', di = d - 'A';
		forr(i,0,30)
			if (y[so][i] < OO and o[di][i] < OO)
				mn = min(mn, y[so][i] + o[di][i]);
		if (mn != OO) {
			ot(mn);
			forr(i,0,30)
				if (mn == y[so][i] + o[di][i])
					otc(' '), otc(i + 'A');
			puts("");
		} else
			puts("You will never meet.");
	}
	return 0;
}
