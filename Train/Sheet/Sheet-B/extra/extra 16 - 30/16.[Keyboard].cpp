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
#define forr(i,j, n) for(i = j;i < n;i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

using ll = long long int;

map<char, ll> T;
vector<string> G;
string s;

int main() { // dfil
	fl(); //TODO

	ll n, m, d, i, j, x, y;
	cin >> n >> m >> d, d *= d;
	forr(i,0,n and cin>>s)
		G.pb(s);
	forr(i,0,n)
		forr(j,0,m)
		{
			if (T.find(G[i][j]) == T.end())
				T[G[i][j]] = 1000000000;
			if (G[i][j] == 'S')
				continue;
			forr(x,0,n)
				forr(y,0,m)
					if (G[x][y] == 'S')
						T[G[i][j]] = min(T[G[i][j]],
								((i - x) * (i - x) + (y - j) * (y - j)));
		}
	ll q;
	cin >> q;
	char c;
	ll e = 'A' - 'a';
	ll ans = 0;
	bool f;
	forr(i,0,q and cin >> c)
	{
		f = false;
		if (isupper(c))
			c -= e, f = 1;

		if (T.find(c) == T.end() or (f and T.find('S') == T.end()))
			return cout << -1, 0;
		if (T[c] > d and f)
			ans++;
	}
	cout << ans;

	return 0;
}
