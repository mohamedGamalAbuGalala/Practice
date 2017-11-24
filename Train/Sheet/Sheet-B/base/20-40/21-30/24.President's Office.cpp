#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
int main() {
	file();
	int n, m, v[26] { 0 }, res = 0;
	char c;
	string a[101];
	scanf("%d%d ", &n, &m);
	scanf("%c", &c);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] == c) {
				if (i > 0 && a[i - 1][j] != c && a[i - 1][j] != '.'
						&& !v[a[i - 1][j] - 'A'])
					res++, v[a[i - 1][j] - 'A'] = 1;
				if (i < n - 1 && a[i + 1][j] != c && a[i + 1][j] != '.'
						&& !v[a[i + 1][j] - 'A'])
					res++, v[a[i + 1][j] - 'A'] = 1;
				if (j > 0 && a[i][j - 1] != c && a[i][j - 1] != '.'
						&& !v[a[i][j - 1] - 'A'])
					res++, v[a[i][j - 1] - 'A'] = 1;
				if (j < m - 1 && a[i][j + 1] != c && a[i][j + 1] != '.'
						&& !v[a[i][j + 1] - 'A'])
					res++, v[a[i][j + 1] - 'A'] = 1;
			}
	cout << res;
	return 0;
}
