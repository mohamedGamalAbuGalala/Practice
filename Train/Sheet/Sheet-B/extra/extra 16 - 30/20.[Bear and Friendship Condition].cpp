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
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;
typedef vector<int> vi;
vi adj[150123];
bool vs[150123];

void dfs(int a, lli & cV, lli & cE) {
	vs[a] = 1, ++cV, cE += sz(adj[a]);
	for (int b : adj[a])
		if (!vs[b])
			dfs(b, cV, cE);
}

int main() { // dfil
	fl(); //TODO
	int n, m, a, b;
	in(n), in(m);
	while (m-- and in(a) and in(b))
		adj[a].pb(b), adj[b].pb(a);

	forr(i,1,n+1)
		if (!vs[i]) {
			lli cV = 0, cE = 0;
			dfs(i, cV, cE);
			if (cE != (cV * (cV - 1)))
				return puts("NO"), 0;
		}
	puts("YES");
	return 0;
}
