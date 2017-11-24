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
const int N = 1e4 + 5;
const int OO = 1e9;
typedef pair<lli, string> lls;

int n, k, t, res = OO, ar[N];
map<ii, int> memo;

void slv(int l = 0, int r = n - 1, int sm = 0) {
	if (l >= r or sm >= res) {
		if (sm < res)
			res = sm;
		return;
	}
	int &ret = memo[ii(l, r)];
	if (ret == 0 or sm < ret) {
		ret = sm;
		if (ar[r] != ar[l])
			slv(l, r - 1, sm + 1), slv(l + 1, r, sm + 1);
		else
			slv(l + 1, r - 1, sm);
	}
}

int main() {
	file();
	in(t);
	for (int tt = 1; tt <= t; ++tt) {
		memo.clear();
		in(n), in(k);
		for (int i = 0; i < n and in(ar[i]); ++i)
			;
		res = k + 1;
		slv();
		if (res > k)
			printf("Case %d: Too difficult\n", tt);
		else if (!res)
			printf("Case %d: Too easy\n", tt);
		else
			printf("Case %d: %d\n", tt, res);
	}
	return 0;
}
