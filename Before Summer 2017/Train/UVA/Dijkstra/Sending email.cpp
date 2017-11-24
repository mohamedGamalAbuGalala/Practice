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

const lli maxN = 20000 + 10;
const lli maxE = 1e5 + 10;

vii ar[maxN];
int n, m, s, e, T, t, v[maxN];

void dijkstra(){
	priority_queue<ii> q;
	q.push(ii(0,s));
	while(q.size()){
		int cur = q.top().second, cost = -q.top().first;
		q.pop();
		if(v[cur]) continue;
		v[cur] = 1;
		if(cur == e){
			cout<<cost<<"\n";
			return;
		}
		for (int i = 0; i < (int)ar[cur].size(); ++i) {
			int to = ar[cur][i].first,co = ar[cur][i].second;
			if(v[to]) continue;
			q.push(ii(-co-cost,to));
		}
	}
	cout<<"unreachable\n";
}

int main() {
	//freopen("in.txt", "r", stdin);
	cin >> T;
	while (T--) {
		cin >> n >> m >> s >> e;
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			ar[u].pb(ii(v, c));
			ar[v].pb(ii(u, c));
		}
		printf("Case #%d: ", ++t);
		dijkstra();
		memset(ar, 0, sizeof ar);
		memset(v, 0, sizeof v);
	}
}
