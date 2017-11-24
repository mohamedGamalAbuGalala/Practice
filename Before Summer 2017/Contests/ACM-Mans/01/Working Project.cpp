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
lli n, m, s, e, l, best, second = 0, pub;
vi res;
vector<ii> g;
lli w[maxN], www[maxN];

void chng(lli f, lli t, lli co) {
	for (lli i = 0; i < (lli) g.size(); ++i) {
		if ((g[i].first == f && g[i].second == t)
				|| (g[i].first == t && g[i].second == f))
			www[i] = co;
	}
}

int mark(vi s) {
	int ll = (int) INF, sm = 0, ret = 0;
	for (int i = 0; i < (int) s.size() - 1; ++i) {
		int f = s[i], t = s[i + 1];
		for (lli j = 0; j < (lli) g.size(); ++j) {
			if (((g[j].first == f && g[j].second == t)
					|| (g[j].first == t && g[j].second == f))) {
				if (www[j] == 0)
					www[j] = 1, ll = j, sm++, ret++;
				else
					break;
			}
		}
	}
	ret--;
	www[ll] += (l - best) - sm +1;
	ret += www[ll];
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
			if (second == 1) {
				cost += mark(cnode.path);
			}
			return cost;
		}
		for (lli i = 0; i < (lli) ar[cur].size(); ++i) {
			lli to = ar[cur][i].first, co = ar[cur][i].second + cost;
			if (co < 0)
				co = (lli) INF;
//			if (co == cost && second == 1) {
//				ar[cur][i].second = pub;
//				chng(cur, to, pub);
//			}
//			co = ar[cur][i].second + cost;
//			if (co < 0)
//				co = (lli) INF;
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
	for (lli j = 0; j < n; ++j)
		ar[j].clear();
	for (lli i = 0; i < (lli) g.size(); ++i) {
		lli f = g[i].first, t = g[i].second, ww = w[i];
		ar[f].pb(ii(t, ww));
		ar[t].pb(ii(f, ww));
	}
}

void copy() {
	for (lli i = 0; i < (lli) g.size(); ++i)
		w[i] = www[i];
}

void b_s(int s, int e) {
	while (s <= e) {
		int mid = (s + e) / 2;
		pub = mid;
		init();
		best = dijkstra();
		if (best < l)
			s = mid + 1;
		else if (best > l)
			e = mid - 1;
		else
			return;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	map<ii, lli> v;
	scanf("%lld %lld %lld %lld %lld\n", &n, &m, &l, &s, &e);
	for (lli i = 0; i < m; ++i) {
		lli f, t, ww;
		scanf("%lld %lld %lld\n", &f, &t, &ww);
		g.pb(ii(f, t));
		w[i] = ww;
		www[i] = ww;
	}
	init();
	best = dijkstra();
	for (lli i = 0; i < n; ++i) {
		for (lli j = 0; j < (lli) ar[i].size(); ++j) {
			if (ar[i][j].second == 0)
				ar[i][j].second = (int) INF;
		}
	}
	lli worst = dijkstra();
	if (worst != l) {
		init();
		if (worst < l || best > l) {
			cout << "No";
			return 0;
		}
		second = 1;

		init();
		best = dijkstra();

//	pub = 1;
//	b_s(pub, l - best);
		if (best > l) {
			cout << "NO";
			return 0;
		}
	}
	copy();
	cout << "YES\n";
	for (lli i = 0; i < (lli) g.size(); ++i) {
		if (w[i] == 0)
			w[i] = 1;
		lli f = g[i].first, t = g[i].second, ww = w[i];
		cout << f << " " << t << " " << ww << "\n";
	}
	return 0;
}
