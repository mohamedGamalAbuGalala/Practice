#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

vector<int> ar[101];
int dep[101];

int main() {
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		ar[u].pb(v);
	}
	queue<int> q;
	q.push(1);
	while (q.size()) {
		int cur = q.front(), si = ar[cur].size();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < si; ++i)
			q.push(ar[cur][i]);
	}

	cout<<"\n";
	q.push(1);
	dep[1] = 0;
	while (q.size()) {
		int cur = q.front(), si = ar[cur].size();
		q.pop();
		for (int i = 0; i < si; ++i) {
			int to = ar[cur][i];
			dep[to] = dep[cur] + 1;
			q.push(to);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout<<dep[i]<<" ";
	return 0;
}
/*
8
1 2
1 6
1 8
2 3
2 4
4 5
6 7



 */
