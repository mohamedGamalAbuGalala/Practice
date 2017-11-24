//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

#define INF 1e18
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 4e4 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int v[8][8], x, y, tx, ty;

int xx[] { 2, 2, 1, 1, -1, -1, -2, -2 };
int yy[] { 1, -1, 2, -2, 2, -2, 1, -1 };

int slv(int ys, int xs, int yd, int xd) {
	memset(v, 0, sizeof v);
	queue<ii> q;
	q.push( { xs, ys }), v[xs][ys] = 1;
	for (int co = 0, sz = q.size(); !q.empty(); ++co, sz = q.size())
		while (sz--) {
			x = q.front().first, y = q.front().second, q.pop();
			if (x == xd && y == yd)
				return co;
			for (int i = 0; i < 8; ++i) {
				tx = x + xx[i], ty = y + yy[i];
				if (tx > -1 && tx < 8 && ty > -1 && ty < 8 && !v[tx][ty])
					v[tx][ty] = 1, q.push( { tx, ty });
			}
		}
	return -1;
}
int main() {
	file();
	string c1, c2;
	while (cin >> c1 >> c2)
		printf("To get from %s to %s takes %d knight moves.\n", c1.c_str(),
				c2.c_str(),
				slv(c1[0] - 'a', c1[1] - '0' - 1, c2[0] - 'a',
						c2[1] - '0' - 1));
	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
