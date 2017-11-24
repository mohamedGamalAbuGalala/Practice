#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
typedef vector<int> vi;
#define forr(i,j, n) for(int i = j;i < n;i++)
const int OO = 1e9 + 5;
#define in(n) scanf("%d",&n)	//scan int
vi adj[100010];
vi color;
int n, u, v, nn;
using lli = long long int;
lli cnt[2];

int main() { // dfil
	file(); //TODO
	in(n);
	forr(i,0,n-1 and in(u) and in(v))
		adj[u].pb(v), adj[v].pb(u);
	color.assign(n + 1, OO);
	queue<int> q;
	q.push(1);
	color[1] = 0;
	cnt[0]++;
	while (sz(q)) {
		u = q.front(), q.pop(), nn++;
		for (auto v : adj[u])
			if (color[v] == OO)
				color[v] = 1 - color[u], q.push(v), cnt[color[v]]++;
	}
	cout << ((cnt[0] * cnt[1]) - (nn - 1));
	return 0;
}
