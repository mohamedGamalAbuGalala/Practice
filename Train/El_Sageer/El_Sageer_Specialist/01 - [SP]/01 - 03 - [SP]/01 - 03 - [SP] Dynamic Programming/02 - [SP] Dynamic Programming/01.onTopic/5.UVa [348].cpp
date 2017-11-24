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
#define mem(a,b) memset(a,b,sizeof(a))
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define otc(x) printf("%c", x)	//output char
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)
typedef pair<int, int> ii;
#define F first
#define S second
const int OO = 1e9 + 5;

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

ii d[11];
using lli = long long int;
lli dp[11][11];
map<ii, int> p;
int n, tt;

lli slv(int i, int j) {
	if (i == j)
		return 0;
	lli &ret = dp[i][j];
	if (ret == -1) {
		p[ii(i, j)] = ret = OO;
		forr(k, i, j)
		{
			lli ret2 = slv(i, k) + slv(k + 1, j) + d[i].F * d[k].S * d[j].S;
			if (ret2 < ret)
				ret = ret2, p[ii(i, j)] = k;
		}
	}
	return ret;
}

void print(int i, int j) {
	if (i == j)
		otc('A'), ot(i + 1);
	else
		otc('('), print(i, p[ii(i, j)]), ots(" x "), print(p[ii(i, j)] + 1,
				j), otc(')');
}

int main() { // dfil
	fl(); //TODO
	while (in(n) and n) {
		mem(dp, -1), p.clear();
//		forr(i, 0, n and in(d[i].F) and in(d[i].S));
//		printf("Case %d: ", ++tt), slv(0, n - 1), print(0, n - 1), ln();
		forr(i, 0, n and in(d[i].F) and in(d[i].S));
		forr(i,0,n)
			dp[i][i] = 0;
		forr(l,2,n+1)
			forr(i,0,n-l+1)
			{
				int j = i + l - 1;
				dp[i][j] = OO;
				forr(k,i,j)
				{
					int q = dp[i][k] + dp[k + 1][j] + d[i].F * d[k].S * d[j].S;
					if (q < dp[i][j])
						dp[i][j] = q, p[ii(i, j)] = k;
				}
			}
		printf("Case %d: ", ++tt), print(0, n - 1), ln();
	}
	return 0;
}
