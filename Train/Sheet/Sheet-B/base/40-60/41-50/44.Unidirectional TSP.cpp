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
	printf("%d ", x);
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
const int N = 1e9 + 5;
const int OO = 1e9;
typedef pair<lli, string> lls;

int ar[11][101], pth[11][101], mem[11][101], n, m;

int slv(int x, int y) {
	if (y == m)
		return ar[x][y];  // cout<<mn;    // print path

	int d[] { x + 1, x, x - 1 }, &ret = mem[x][y];
	if (ret == OO) {
		d[0] = (d[0] > n) ? 1 : d[0], d[2] = (d[2] < 1) ? n : d[2];
		for (int i = 0; i < 3; i++) {
			int val = slv(d[i], y + 1) + ar[x][y];
			if (val < ret || (ret == val && pth[x][y] > d[i]))
				ret = val, pth[x][y] = d[i];
		}
	}
	return ret;
}

int main() {
	file();
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m and in(ar[i][j]); mem[i][j] = OO, ++j)
				;
		int ma = OO;
		int r = 0;
		for (int i = 1; i <= n; i++) {
			int res = slv(i, 1);
			if (res < ma)
				ma = res, r = i;
		}
		for (int i = 1; i <= m; i++) {
			printf((i == 1) ? "%d" : " %d", r);
			r = pth[r][i];
		}
		printf("\n%d\n", ma);
	}
	return 0;
}
