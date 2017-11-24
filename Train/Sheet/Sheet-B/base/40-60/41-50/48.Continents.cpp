#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
bool in(int &x) {
//	return scanf("%lf", &x);		// double
	return scanf("%d", &x);			// int
//	return scanf("%lld", &x);			// long long int
}
void ot(int x) {
	printf("%d\n", x);
//	printf("%lld ", x);		//  	long long int
//	printf("%.3lf ", x);
}
void ln() {
	scanf("\n");
}
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define cl(v,d) memset(v,d,sizeof(v))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))

const int MN = 1e3 + 5;
const int MW = 1e3 + 5;

const int OO = 1e9;
typedef pair<lli, string> lls;

char ar[21][21], land;
int n, m, x, y, v[21][21], ans;

int tx[] { 0, 0, 1, -1 };
int ty[] { 1, -1, 0, 0 };

void fill(int x, int y) {
	if (y < 0)
		y = m - 1;
	if (y >= m)
		y = 0;
	if (ar[x][y] == '.' or ar[x][y] != land or x < 0 or x >= n)
		return;
	ar[x][y] = '.';
	for (int i = 0; i < 4; ++i)
		fill(x + tx[i], y + ty[i]);
	ans++;
	return;
}

int main() {
	file();
	while (scanf("%d %d\n", &n, &m) == 2) {
		mem(v, 0);
		for (int i = 0; i < n; ++i)
			cin >> ar[i];
		in(x), in(y);
		land = ar[x][y];
		int res = 0;
		fill(x, y);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				ans = 0;
				if (ar[i][j] != '.')
					fill(i, j);
				res = max(res, ans);
			}
		ot(res);
	}
	return 0;
}
