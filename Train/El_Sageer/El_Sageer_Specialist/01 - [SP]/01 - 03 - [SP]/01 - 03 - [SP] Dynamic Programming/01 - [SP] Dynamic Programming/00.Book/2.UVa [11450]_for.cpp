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

int M, C, P[55][55];
bool reach[55][222];

int main() { // dfil
	fl(); //TODO
	int T, ans;
	in(T);
	while (T-- and in(M) and in(C)) {
		mem(reach, 0);
		forr(i,0,C and in(P[i][0]))
			forr(j, 1, P[i][0]+1 and in(P[i][j]));
		reach[0][M] = 1;
		forr(g,0,C)
			forr(m,0,M+1)
				if (reach[g][m])
					forr(i,1,P[g][0]+1)
						if (m - P[g][i] >= 0 and !reach[g + 1][m - P[g][i]])
							reach[g + 1][m - P[g][i]] = 1;
		ans = -1;
		forr(i,0,M+1)
			if (reach[C][i]) {
				ans = i;
				break;
			}
		if (ans < 0)
			puts("no solution");
		else
			ot(M-ans), ln();
	}
	return 0;
}
