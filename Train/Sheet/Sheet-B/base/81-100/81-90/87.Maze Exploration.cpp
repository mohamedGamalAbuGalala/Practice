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
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

vector<string> a;
int ii = 0, sx, sy;
int dx[] { 1, -1, 0, 0 };
int dy[] { 0, 0, 1, -1 };
void flood(int x, int y) {
	if (x < 0 or x >= ii - 1 or y < 0 or y >= sz(a[x])
			or (a[x][y] != ' ' and a[x][y] != '*'))
		return;
	a[x][y] = '#';
	forr(i,0,4)
		flood(x + dx[i], y + dy[i]);
}

int main() { // dfil
	fl(); //TODO
	int T;
	cin >> T, getchar();
	while (T--) {
		string p;
		ii = 0;
		a.assign(100, "");
		while (getline(cin, p) and p[0] != '_') {
			a[ii] = p;
			auto f = p.find('*');
			if (f != string::npos)
				sx = ii, sy = f;
			ii++;
		}
		flood(sx, sy);
		forr(i,0,ii)
			cout << a[i] << "\n";
		cout << p << "\n";
	}
	return 0;
}
