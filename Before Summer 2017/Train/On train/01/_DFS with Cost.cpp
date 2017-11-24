#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> >arr[100];
int depth[101];
int n;
int answer[101];
int DFS(int cur, int sum) {
	answer[cur] = sum;
	for (int i = 0; i < arr[cur].size(); i++) {
		answer[cur] = max(answer[cur], DFS(arr[cur][i].first, arr[cur][i].second + sum));
	}
	return answer[cur];
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		arr[u].push_back(make_pair(v, c));
	}
	DFS(1, 0);
	for (int i = 1; i <= n; i++) {
		cout << i << "-->" << answer[i] << endl;
	}
}
