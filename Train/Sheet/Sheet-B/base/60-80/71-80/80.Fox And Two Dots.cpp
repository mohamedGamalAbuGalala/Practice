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
int i, j, k;
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int dx[] { 1, -1, 0, 0 };
int dy[] { 0, 0, 1, -1 };
bool cyc = 0;
int n, m, vs[55][55], col;
char a[55][55], cur;

void dfs(int ii, int jj, int pi = -1, int pj = -1) {
	if (vs[ii][jj]) {
		if (vs[ii][jj] == col)
			cyc = 1;
		return;
	}
	vs[ii][jj] = col;
	forr(i,0,4)
	{
		int ti = dx[i] + ii, tj = dy[i] + jj;
		if ((ti != pi or tj != pj) and ti < n and ti >= 0 and tj < m and tj >= 0
				and a[ti][tj] == cur)
			dfs(ti, tj, ii, jj);
	}
}

int main() { // dfil
	fl(); //TODO
	cin >> n >> m;
	forr(i,0,n)
		forr(j, 0, m and cin>>a[i][j]);
	forr(i,0,n)
		forr(j, 0, m)
		{
			if (!vs[i][j])
				cur = a[i][j], col = cur, dfs(i, j);
		}
	if (cyc)
		puts("Yes");
	else
		puts("No");
	return 0;
}
