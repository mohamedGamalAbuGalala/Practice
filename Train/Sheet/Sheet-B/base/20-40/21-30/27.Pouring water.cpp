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

//int v[N][N];
//int cost[N][N];

int v[2][2][N], x, y, z;
//int cost[2][2][N];

int a, b, c, ca, cb, co, T;
queue<ii> q;

void get(int ca ,int cb) {
	if (!ca)
		x = 0, y = 1, z = cb;
	else if (!cb)
		x = 1, y = 1, z = ca;
	else if (ca == a)
		x = 0, y = 0, z = cb;
	else if (cb == b)
		x = 1, y = 0, z = ca;
}

void Try(int a, int b) {
	//	if (!v[a][b])
	//		v[a][b] = 1, cost[a][b] = co, q.push( { a, b });
	get(a,b);
	if (!v[x][y][z])
		v[x][y][z] = 1, q.push( { a, b });
}

void clear() {
	memset(v, 0, sizeof v);
	queue<ii> tmp;
	swap(tmp, q);
}

void slv() {
	clear();
	cin >> a >> b >> c;
//	v[0][0] = 1;
	v[0][1][0] = 1;
	q.push( { 0, 0 });

	int sz;
	for (co = 0, sz = q.size(); !q.empty(); ++co, sz = q.size())
		while (sz--) {
			ca = q.front().first, cb = q.front().second, q.pop();
			if (ca == c or cb == c) {
				cout << co << "\n";
				return;
			}
			Try(0, cb), Try(ca, 0);
			Try(a, cb), Try(ca, b);
			Try(ca + min(a - ca, cb), cb - min(a - ca, cb));
			Try(ca - min(b - cb, ca), cb + min(b - cb, ca));
		}
	/*
	 while (q.size()) {
	 ca = q.front().first, cb = q.front().second, q.pop();
	 if (ca == c or cb == c) {
	 cout << cost[ca][cb] << "\n";
	 return;
	 }
	 co = cost[ca][cb] + 1;
	 Try(0, cb), Try(ca, 0);
	 Try(a, cb), Try(ca, b);
	 Try(ca + min(a - ca, cb), cb - min(a - ca, cb));
	 Try(ca - min(b - cb, ca), cb + min(b - cb, ca));
	 }*/

	cout << "-1\n";
}
int main() {
	file();
	cin >> T;
	while (T--)
		slv();
	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
