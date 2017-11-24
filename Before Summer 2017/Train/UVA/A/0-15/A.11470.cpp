#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int ar[11][11], n, t = 0;
vector<int> res;

void solve(int s, int n, int e) {
	if (n <= 0)
		return;
	int ret = 0;
	for (int i = s; i <= e; ++i)
		ret += ar[s][i];
	if (n != 1)
		for (int i = s; i <= e; ++i)
			ret += ar[e][i];
	for (int i = s + 1; i <= e - 1; ++i)
		ret += ar[i][s];
	for (int i = s + 1; i <= e - 1; ++i)
		ret += ar[i][e];
	res.pb(ret);
	solve(s + 1, n - 2, e - 1);
	return;
}

int main() {
	freopen("in.txt", "r", stdin);
	while (scanf("%d\n", &n) && n != 0) {
		res.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> ar[i][j];
		solve(0, n, n - 1);
		printf("Case %d: ", ++t);
		int rsi = res.size();
		for (int i = 0; i < rsi; ++i) {
			cout << res[i];
			if (i != rsi - 1)
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
