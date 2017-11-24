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
#define ins(n) scanf("%s",n)	//scan char[]
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define F first
#define S second

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

typedef pair<int, int> iip;
iip S[1123], N[1123];
iip dp[1123][1123];
int T, n, m;

iip slv(int i, int j) {
	if (i >= n or j >= m)
		return iip(0, 0);
	iip &ret = dp[i][j], ret2;
	if (ret.F == -1) {
		ret = iip(0, 0);
		/*
		 *
		 *  N[i].F --> OS type of city
		 *  N[i].S --> trade value of city
		 *
		 */

		if (N[i].F == S[j].F) { // OS of north city == OS of south city		(Build)
			int v = N[i].S + S[j].S;
			ret2 = slv(i + 1, j + 1); // calc cost of building the bridge
			if (ret.F <= ret2.F + v) {
				if (ret.F == ret2.F + v)
					ret.S = min(ret.S, ret2.S + 1);
				else {
					ret.F = ret2.F + v;
					ret.S = ret2.S + 1;
				}
			}
		}

		ret2 = slv(i + 1, j);	// ignore the north city
		if (ret.F <= ret2.F) {
			if (ret.F == ret2.F)
				ret.S = min(ret.S, ret2.S);
			else {
				ret.F = ret2.F;
				ret.S = ret2.S;
			}
		}

		ret2 = slv(i, j + 1);	// ignore the south city
		if (ret.F <= ret2.F) {
			if (ret.F == ret2.F)
				ret.S = min(ret.S, ret2.S);
			else {
				ret.F = ret2.F;
				ret.S = ret2.S;
			}
		}
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	string sn, st;
	map<string, int> tsti; // to represent OS types as integers instead of strings to faster comparisons
	in(T);
	while (T-- and in(n)) {
		int tp = 1;
		mem(dp, -1), tsti.clear();	// clearing
		/*
		 *
		 *  N[i].F --> OS type of city
		 *  N[i].S --> trade value of city
		 *
		 */
		forr(i,0,n and cin>>(sn)>>(st) and in(N[i].S))
		{
			if (!tsti[st])
				tsti[st] = tp++;
			N[i].F = tsti[st];
		}
		in(m);
		forr(i,0,m and cin>>(sn)>>(st) and in(S[i].S))
		{
			if (!tsti[st])
				tsti[st] = tp++;
			S[i].F = tsti[st];
		}
		iip ret = slv(0, 0);
		cout << ret.F << " " << ret.S << "\n";
	}
	return 0;
}
