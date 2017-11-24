#include <bits/stdc++.h>

#define INF 1e6
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 20000 + 10;
const lli maxE = 1e5 + 10;

struct node {
	int i, j, c;bool operator <(const node &b) const {
		return c > b.c;
	}
};

int ar[102][102], v[102][102], n, m, a, b, t;
int di[] { 1, -1, 0, 0 };
int dj[] { 0, 0, 1, -1 };

bool valid(int i, int j) {
	return i < n && i >= 0 && j < m && j >= 0;
}

void clear() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ar[i][j] = -1, v[i][j] = -1;
}

int dijkstra() {
	priority_queue<node> q;
	node n;
	n.i = 0, n.j = 0, n.c = ar[0][0];
	q.push(n);
	while (q.size()) {
		n = q.top();
		q.pop();
		v[n.i][n.j] = 1;
		if (n.i == (a - 1) && n.j == (b - 1))
			return n.c;
		for (int i = 0; i < 4; ++i) {
			node tmp;
			tmp.i = n.i + di[i];
			tmp.j = n.j + dj[i];
			if (valid(tmp.i, tmp.j) && v[tmp.i][tmp.j] == -1) {
				tmp.c = n.c + ar[tmp.i][tmp.j];
				q.push(tmp);
			}
		}
	}
	return -1;
}

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		clear();
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k)
				cin >> ar[j][k];
		cin >> a >> b >> t;
		int ret = dijkstra();
		if (ret > t)
			cout << "NO\n";
		else
			cout << "YES\n" << t - ret << "\n";
	}
}

