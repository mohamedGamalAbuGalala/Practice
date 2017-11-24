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

int n, t, res = OO;
string ar;
int memo[1001][1001];

void slv(int l = 0, int r = n - 1, int sm = 0) {
	if (l >= r or sm >= res) {
		if (sm < res)
			res = sm;
		return;
	}
	int &ret = memo[l][r];
	if (ret == -1 or sm < ret) {
		ret = sm;
		if (ar[r] != ar[l])
			slv(l + 1, r - 1, sm + 1), slv(l + 1, r, sm + 1), slv(l, r - 1,
					sm + 1);
		else
			slv(l + 1, r - 1, sm);
	}
}

int main() {
	file();
	in(t);
	for (int tt = 1; tt <= t; ++tt) {
		mem(memo, -1);
		cin >> ar;
		n = sz(ar), res = n + 1;
		slv();
		printf("Case %d: %d\n", tt, res);
	}
	return 0;
}
