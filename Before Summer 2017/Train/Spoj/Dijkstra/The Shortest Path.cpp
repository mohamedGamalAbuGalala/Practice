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
typedef vector<vector<ii>> vvii;

const lli maxN = 10000 + 10;
const lli maxE = 1e5 + 10;

int s, e, T, v[maxN];
vii ar[maxN];

void dijksra() {
	priority_queue<ii> q;
	q.push(ii(0, s));
	while (q.size()) {
		int cur = q.top().second, cost =- q.top().first;
		q.pop();
		if (v[cur])
			continue;
		v[cur] = 1;
		if (cur == e) {
			cout << cost << "\n";
			return;
		}
		for (int i = 0; i < (int) ar[cur].size(); ++i) {
			int to = ar[cur][i].first, co = ar[cur][i].second;
			if (v[to])
				continue;
			q.push(ii(-co - cost, to));
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> T;
	while (T--) {
		memset(ar, 0 , sizeof ar);
		map<string, int> m;
		int n, cnt = 1;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string tmp;
			int r;
			cin >> tmp >> r;
			m[tmp] = cnt;
			for (int j = 0; j < r; ++j) {
				int v, c;
				cin >> v >> c;
				ar[cnt].pb(ii(v, c));
			}
			cnt++;
		}
		int p;
		cin >> p;
		while (p--) {
			string st, en;
			cin >> st >> en;
			s = m[st], e = m[en];
			dijksra();
			memset(v, 0, sizeof v);
		}
	}
}
