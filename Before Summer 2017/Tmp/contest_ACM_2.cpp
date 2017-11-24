#include <bits/stdc++.h>

#define INF 1e18
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 10000;
const lli maxE = 1e5 + 10;

struct node {
	lli ind, cost;
	vi path;bool operator <(const node &b) const {
		return cost > b.cost;
	}
};

node nnode(lli n, lli c, vi p) {
	node node;
	node.ind = n, node.cost = c;
	for (int i = 0; i < (int) p.size(); ++i)
		node.path.pb(p[i]);
	return node;
}

vii ar[maxN];
lli n, m, s, e, l, best, second = 0;
vector<ii> g;
lli w[maxN];

lli mark(vi s) {
	lli ff = -1, ret = 0;
	for (int i = 0; i < (int) s.size() - 1; ++i) {
		int f = s[i], t = s[i + 1];

		for (int j = 0; j < (int) g.size(); ++j)

			if (((g[j].first == f && g[j].second == t)
					|| (g[j].first == t && g[j].second == f))) {

				if (w[j] == 0) {

					if (ff == -1)
						w[j] = l - best, ff = j;
					else
						w[j] = 1, ret++, w[ff]--;
				} else
					break;
			}
	}

	if (ff != -1 && w[ff] <= 0)
		w[ff] = 1;
	if (ff != -1)
		ret = ret + w[ff];
	return ret;
}

lli dijkstra() {
	lli v[maxN] = { 0 };
	priority_queue<node> q;
	vi pp;
	pp.pb(s);
	node n = nnode(s, 0, pp);
	q.push(n);
	while (q.size()) {

		lli cur = q.top().ind, cost = q.top().cost;
		vi path = q.top().path;
		node cnode = nnode(cur, cost, path);
		q.pop();

		if (v[cur])
			continue;
		v[cur] = 1;

		if (cur == e) {
			if (second == 1)
				cost += mark(cnode.path);
			return cost;
		}

		for (int i = 0; i < (int) ar[cur].size(); ++i) {
			lli to = ar[cur][i].first, co = ar[cur][i].second + cost;
			if (co < 0)
				co = (int) INF;
			if (v[to])
				continue;
			node tmp = nnode(to, co, path);
			tmp.path.pb(to);
			q.push(tmp);
		}

	}
	return -1;
}

void init() {
	for (int j = 0; j < n; ++j)
		ar[j].clear();
	for (int i = 0; i < (int) g.size(); ++i) {
		lli f = g[i].first, t = g[i].second, ww = w[i];
		ar[f].pb(ii(t, ww));
		ar[t].pb(ii(f, ww));
	}
}

void yeeee() {
	cout << "YES\n";
	for (int i = 0; i < (int) g.size(); ++i) {
		if (w[i] == 0)
			w[i] = INF;
		lli f = g[i].first, t = g[i].second, ww = w[i];
		cout << f << " " << t << " " << ww << "\n";
	}
}

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%lld %lld %lld %lld %lld\n", &n, &m, &l, &s, &e);
//	cin >> n >> m >> l >> s >> e;
	for (int i = 0; i < m; ++i) {
		lli f, t, ww;
		scanf("%lld %lld %lld\n", &f, &t, &ww);
//		cin >> f >> t >> ww;
		g.pb(ii(f, t));
		w[i] = ww;
	}

	init();
	best = dijkstra();

	if (best == l) {
		yeeee();
		return 0;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < (int) ar[i].size(); ++j)
			if (ar[i][j].second == 0)
				ar[i][j].second = (int) INF;
	lli worst = dijkstra();

	if (worst == l) {
		yeeee();
		return 0;
	}

	if (worst < l || best > l) {
		cout << "No";
		return 0;
	}
	second = 1;

	init();
	best = dijkstra();
	if (best > l) {
		cout << "NO";
		return 0;
	}

	if (best == l) {
		yeeee();
		return 0;
	}

	return 0;
}
