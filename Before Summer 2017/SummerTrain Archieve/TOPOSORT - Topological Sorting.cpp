///TOPOSORT - Topological Sorting

#include <iostream>
#include <vector>
#include <set>
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr[10001];
int cnt[10001];
set<int> ready;
vector<int> ans;

int main() {
	int i, f, s, cur;

	scanf("%d%d", &n, &m);
	for (i = 0; i<m; i++) {
		scanf("%d%d", &f, &s);
		arr[f].push_back(s);
		cnt[s]++;
	}

	for (i = 1; i <= n; i++)
	if (!cnt[i])
		ready.insert(i);

	while (ready.size()) {
		cur = *ready.begin();
		ready.erase(ready.begin());
		ans.push_back(cur);

		for (i = 0; i<arr[cur].size(); i++) {
			cnt[arr[cur][i]]--;
			if (cnt[arr[cur][i]] == 0)
				ready.insert(arr[cur][i]);
		}
	}

	if (ans.size() != n) cout << "Sandro fails.";
	else {
		for (i = 0; i<n; i++)
			printf("%d ", ans[i]);
	}
	return 0;
}
