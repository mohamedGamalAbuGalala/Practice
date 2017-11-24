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

typedef vector<int> vi;
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ln() printf("\n")		//output new line
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

vi ar[101][101];
int vis[101];

int bfs(int s, int e, int col, int sz = 1, int cur = 0) {
	queue<int> q;
	q.push(s);
	for (; sz(q); sz = sz(q))
		while (sz--) {
			cur = q.front(), q.pop();
			if (cur == e)
				return 1;
			for (auto it : ar[col][cur])
				if (!vis[it])
					vis[it] = 1, q.push(it);
		}
	return 0;
}
int main() { // dfil
	fl(); //TODO

	int n, m, u, v, c, q, ans = 0;
	in(n), in(m);
	forr(i,0,m and in(u) and in(v) and in(c))
		ar[c][u].pb(v), ar[c][v].pb(u);
	in(q);
	forr(i,0,q and in(u) and in(v))
	{
		ans = 0;
		forr(j,0,m+1)
			mem(vis, 0), ans += bfs(u, v, j);
		ot(ans), ln();
	}
	return 0;
}
