#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100];
int m, n;
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
	}
	queue<int> q;
	q.push(1);
	while (q.size()) {
		int cur = q.front();
		cout << cur << " ";
		q.pop();
		for (int i = 0; i < arr[cur].size(); i++)
			q.push(arr[cur][i]);
	}

}
