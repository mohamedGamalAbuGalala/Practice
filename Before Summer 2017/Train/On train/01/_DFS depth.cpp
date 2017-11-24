#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100];
int depth[101];
int n;
int answer[101];
int DFS(int cur, int d) {
	answer[cur] = d;
	for (int i = 0; i < arr[cur].size(); i++)
		answer[cur] = max(answer[cur], DFS(arr[cur][i], d + 1));
	return answer[cur];
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
	}
	DFS(1, 0);
	for (int i = 1; i <= n; i++) {
		cout << i << "-->" << answer[i] << endl;
	}
}
