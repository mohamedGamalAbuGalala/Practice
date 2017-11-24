/*
 Notes::

 Input::

 Output::

 */
#include <bits/stdc++.h>

#define INF 1000000000
#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const lli maxN = 40000 + 10;
const lli maxE = 1e5 + 10;

int v[2][2][maxN], cost[2][2][maxN], co, x, y, z, a, b, c;

queue<ii> q;

void get(int ca, int cb, int & x, int & y, int & z) {
	if (!ca)
		x = 0, y = 1, z = cb;
	else if (ca == a)
		x = 0, y = 0, z = cb;
	else if (!cb)
		x = 1, y = 1, z = ca;
	else if (cb == b)
		x = 1, y = 0, z = ca;
}

void Try(int a, int b) {
	get(a, b, x, y, z);
	if (!v[x][y][z]) {
		v[x][y][z] = 1;
		q.push(ii(a, b));
		cost[x][y][z] = co;
	}
}

void solve() {
	memset(v, 0, sizeof v);
	while (q.size())
		q.pop();
	cin >> a >> b >> c;
	v[0][1][0] = 0;
	cost[0][1][0] = 0;
	q.push(ii(0, 0));
	while (q.size()) {
		int ca = q.front().first, cb = q.front().second;
		q.pop();
		get(ca, cb, x, y, z);
		if (ca == c || cb == c) {
			cout << cost[x][y][z] << "\n";
			return;
		}
		co = cost[x][y][z] + 1;

		Try(0, cb);		// Empty a
		Try(ca, 0);		// Empty b
		Try(a, cb);		// Full a
		Try(ca, b);		// Full b
		Try(ca + min(cb, a - ca), cb - min(cb, a - ca));		// Empty cb in a
		Try(ca - min(ca, b - cb), cb + min(ca, b - cb));		// Empty ca in b
	}
	cout << "-1\n";
}

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();

}
