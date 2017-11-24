/*
 Notes::
	1(i) 2(a)
	3(j) 4
	if( 1(i) <-> 2(a)  && 1(i) <-> 3(j)  )
		then
			2(a) <-> 3(j)
			con[2][3] = min( con[2][3] , con[1][2]  + con[1][3] )
 Input::
4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1
 Output::
3
 */
#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int n, m, s, e, con[105][105], flag[105][105];

void solve() {
	int i, a, j;
	for (i = 1; i <= n; i++)
		for (a = 1; a <= n; a++)
			for (j = 1; j <= n; j++)
				if (flag[a][i] && flag[i][j]) {
					flag[a][j] = 1;
					con[a][j] = min(con[a][j], con[a][i] + con[i][j]);
				}
	return;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int i, a, j, k, c = 0;
	scanf("%d %d %d %d\n", &n, &e, &s, &m);
	memset(flag, 0, sizeof flag);
	memset(con, 99, sizeof con);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &j, &k);
		con[a][j] = k;
		flag[a][j] = 1;
	}
	con[e][e] = 0;		// distance is zero to get from e to e
	solve();
// gets distance between every a , b vertices such that a , b is a V in graph
	for (i = 1; i <= n; i++)
		if (con[i][e] <= s)	// distance between every node and the e
			c++;
	printf("%d\n", c);
	return 0;
}
