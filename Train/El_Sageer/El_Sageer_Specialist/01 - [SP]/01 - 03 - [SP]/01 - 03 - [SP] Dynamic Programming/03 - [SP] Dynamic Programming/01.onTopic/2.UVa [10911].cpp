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
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ins(n) scanf("%s",n)	//scan char[]
#define otf(x) printf("%.2lf", x)// output double/float with 0.00
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)
#define _on(S, j) (S & (1 << j))
#define _tog(S, j) (S ^= (1 << j))
#define mem(a,b) memset(a,b,sizeof(a))
const double OO = 1e9 + 5;
#define EPS 1e-9
#define mem2d(dp,b) fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), b)

struct point {
	int x, y;
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

double dp[(1 << 17) + 5][20];
int n, tt;
point pp[22];

double slv(int msk = 1, int p = 0) {
	if (msk == (1 << (n + 1)) - 1)
		return 0;
	double &ret = dp[msk][p];
	if (fabs(ret - OO) < EPS) {
		forr(i,1,n+1)
			if (!_on(msk, i)) {
				if (!p)
					_tog(msk, i), ret = min(ret, slv(msk, i)), _tog(msk, i);
				else
					_tog(msk, i), ret = min(ret,
							slv(msk, 0) + dist(pp[p], pp[i])), _tog(msk, i);
			}
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	char ss[50];
	while (in(n) and n) {
		n *= 2;
		forr(i, 1, n+1 and ins(ss) and in(pp[i].x) and in(pp[i].y));
		mem2d(dp, OO);
		printf("Case %d: ", ++tt), otf(slv()), ln();
	}
	return 0;
}
