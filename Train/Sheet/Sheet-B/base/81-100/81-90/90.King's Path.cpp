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
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)
#define F first
#define S second
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

typedef pair<int, int> ii;

map<ii, int> vl, vs;
int x, xx, y, yy, n, r, a, b;
int dx[] { 1, -1, 0, 0, -1, -1, 1, 1 };
int dy[] { 0, 0, 1, -1, -1, 1, -1, 1 };

int Bfs() {
	queue<ii> q;
	int sz = 1, co = 0;
	ii cur;
	q.push(ii(x, y));
	for (; sz(q); co++, sz = sz(q))
		while (sz--) {
			cur = q.front(), q.pop();
			if (cur.F == xx and cur.S == yy)
				return co;
			forr(i,0,8)
			{
				int tx = cur.F + dx[i], ty = cur.S + dy[i];
				if (vl[ii(tx,ty)] and !vs[ii(tx,ty)])
					vs[ii(tx,ty)] = 1, q.push(ii(tx, ty));
			}
		}
	return -1;
}
int main() { // dfil
	fl(); //TODO
	in(x), in(y), in(xx), in(yy), in(n);
	forr(i,0,n and in(r) and in(a) and in(b))
		forr(j,a,b+1)
			vl[ii(r,j)] = 1;
	cout << Bfs();
	return 0;
}
