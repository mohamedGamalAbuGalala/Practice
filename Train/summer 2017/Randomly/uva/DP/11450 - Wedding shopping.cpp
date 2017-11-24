#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
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
const int N = 5e4 + 5;
const int OO = 1e9;
typedef pair<lli, string> lls;

int t, m, c, k, x, mem[201][21];
vector<vi> ar;

int slv(int mon = m, int g = 0) {
	if (mon < 0)
		return -OO;
	if (g >= c)
		return m - mon;
	int &ret = mem[mon][g];
	if (ret == -1)
		for (int i = 0; i < sz(ar[g]); ++i)
			ret = max(ret, slv(mon - ar[g][i], g + 1));
	return ret;
}

int main() {
	file();
	in(t);
	while (t--) {
		in(m), in(c), ar.clear(), mem(mem, -1);
		for (int i = 0; i < c; ++i) {
			in(k);
			vi tmp;
			for (int j = 0; j < k and in(x); ++j)
				tmp.pb(x);
			ar.pb(tmp);
		}
		int res = slv();
		if (res == -1)
			cout << "no solution" << "\n";
		else
			cout << res << "\n";
	}
	return 0;
}
