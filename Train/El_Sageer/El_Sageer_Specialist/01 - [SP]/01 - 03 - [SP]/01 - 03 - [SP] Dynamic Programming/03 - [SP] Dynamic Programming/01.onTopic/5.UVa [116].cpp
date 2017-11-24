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
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
const int OO = 1e9 + 5;
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int ar[11][112], pth[11][112], dp[11][112], n, m;

int slv(int x, int y) {
	if (y == m)
		return ar[x][y];

	int d[] { (x + 1 > n) ? 1 : (x + 1), x, (x - 1 < 1) ? n : x - 1 }, &ret =
			dp[x][y];
	if (ret == OO)
		forr(i,0,3)
		{
			int nret = ar[x][y] + slv(d[i], y + 1);
			if (nret < ret or (ret == nret and pth[x][y] > d[i]))
				ret = nret, pth[x][y] = d[i];
		}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	while (in(n) != EOF and in(m)) {
		forr(i,1,n+1)
			forr(j,1,m+1 and in(ar[i][j]))
				dp[i][j] = OO;
		int ma = OO, res;
		int r = 0;
		forr(i,1,n+1)
		{
			res = slv(i, 1);
			if (res < ma)
				ma = res, r = i;
		}
		forr(i,1,m+1)
			printf((i == 1) ? "%d" : " %d", r), r = pth[r][i];
		printf("\n%d\n", ma);
	}
	return 0;
}
