///Mice Maze ( Floyd Warshall)

#include<algorithm>
#include<stdio.h>
#include<vector>
#include<set>
#include<string.h>
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
	int i, a, j, k, c = 0;
	scanf("%d %d %d %d\n", &n, &e, &s, &m);
	memset(flag, 0, sizeof flag);
	memset(con, 99, sizeof con);
	for (i = 0; i<m; i++) {
		scanf("%d %d %d", &a, &j, &k);
		con[a][j] = k;
		flag[a][j] = 1;
	}
	con[e][e] = 0;
	solve();
	for (i = 1; i <= n; i++)
	if (con[i][e] <= s) c++;
	printf("%d\n", c);
	//getchar();getchar();getchar();
	return 0;
}
