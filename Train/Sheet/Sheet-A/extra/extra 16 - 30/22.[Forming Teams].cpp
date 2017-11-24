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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

const int MN = 1e2 + 9;
int f[MN], n, m, ans, v, u;
int root(int v) {
	return f[v] < 0 ? v : f[v] = root(f[v]);
}

int main() { // dfil
	fl(); //TODO
	memset(f, -1, sizeof f);
	cin >> n >> m;
	while (m-- and cin >> u >> v)
		if ((v = root(v)) == (u = root(u)) and ((-f[u]) & 1))
			ans++;
		else
			f[u] += f[v], f[v] = u;
	if ((n - ans) & 1)
		ans++;
	cout << ans;
	return 0;
}
