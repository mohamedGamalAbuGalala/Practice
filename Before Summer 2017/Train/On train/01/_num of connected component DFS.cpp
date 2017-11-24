#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100];
int n, m;
int vis[100];
void DFS(int cur) {
	if (vis[cur])
		return;
	vis[cur]=1;
	for (int i = 0; i < arr[cur].size(); i++) {
		DFS(arr[cur][i]);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt++;
			DFS(i);
		}
	}
	cout << cnt;
}
