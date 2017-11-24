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

const lli maxN = 1e5 + 10;
const lli maxE = 1e5 + 10;

struct node {
	int ind, cost, parent;bool operator <(const node &b) const {
		return cost > b.cost;
	}
};

int n, m, s, e, v[maxN], p[maxN];
vii ar[maxN];

void print(int cur) {
	if(cur == -1) return;
	print(p[cur]);
	cout<<cur<<" ";
}

void dijkstra() {
	priority_queue<node> q;
	node cur;
	cur.ind = 1, cur.cost = 0, cur.parent = -1;
	q.push(cur);
	while (q.size()) {
		cur = q.top();
		q.pop();
		if (v[cur.ind])
			continue;
		v[cur.ind] = 1;
		if (!p[cur.ind])
			p[cur.ind] = cur.parent;
		if (cur.ind == e) {
			print(e);
			return;
		}
		for (int i = 0; i < (int) ar[cur.ind].size(); ++i) {
			if (v[ar[cur.ind][i].first])
				continue;
			node tmp;
			tmp.ind = ar[cur.ind][i].first;
			tmp.cost = ar[cur.ind][i].second + cur.cost;
			tmp.parent = cur.ind;
			q.push(tmp);
		}
	}
	cout<<"-1";
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, c;

		cin >> u >> v >> c;
		ar[u].pb(ii(v, c));
		ar[v].pb(ii(u, c));
	}
	s = 1, e = n;
	dijkstra();
	return 0;
}
