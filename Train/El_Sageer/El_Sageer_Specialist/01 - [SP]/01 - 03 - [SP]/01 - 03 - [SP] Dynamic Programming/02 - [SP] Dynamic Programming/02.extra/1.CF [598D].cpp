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
#define frr(i,j, n) for(int i = j;i >= n;i--)
typedef pair<int, int> ii;
#define F first
#define S second
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define inc(n) scanf("%c ",&n)	//scan char
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

bool vs[1123][1123], a[1123][1123];
int dx[] { -1, 1, 0, 0 };
int dy[] { 0, 0, -1, 1 };
int n, m, T, x, y, ret[1123][1123];
char c;
stack<ii> s;

int dfs(int x, int y) {
	if (a[x][y])
		return 1;
	vs[x][y] = 1;
	s.push(ii(x, y));
	int ret = 0;
	forr(i,0,4)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx <= n and nx and ny and ny <= m and !vs[nx][ny]) {
			if (!a[nx][ny])
				ret += dfs(nx, ny);
			else
				ret++;
		}
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	in(n), in(m), in(T), getchar();
	forr(i,1,n+1)
		forr(j,1,m+1 and inc(c))
			a[i][j] = c == '*';
	forr(i,1,n+1)
		forr(j,1,m+1)
			if (!vs[i][j] and !a[i][j] and !ret[i][j]) {
				int mx = dfs(i, j);
				while (sz(s))
					ret[s.top().F][s.top().S] = mx, s.pop();
			}
	forr(i,0,T and in(x) and in(y))
		ot(ret[x][y]), ln();
	return 0;
}
