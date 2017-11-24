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
#define ot(x) printf("%d", x)	//output int
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define pb push_back
#define all(v) v.begin(), v.end()

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

vector<int> xs[26];
int res = 1, idx = -1;
bool fa[26];
int main() { // dfil
	fl(); //TODO
	string a, b;
	cin >> a >> b;
	forr(i,0,sz(a))
		xs[a[i] - 'a'].pb(i), fa[a[i] - 'a'] = 1;
	for (auto ch : b)
		if (!fa[ch - 'a'])
			return ot(-1), 0;
	for (int ch : b) {
		ch -= 'a';
		auto it = upper_bound(all(xs[ch]), idx);
		if (it == xs[ch].end())
			res++, idx = xs[ch][0];
		else
			idx = (*it);
	}
	cout << res;
	return 0;
}
