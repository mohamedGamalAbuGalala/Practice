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

int t, n, v[MN], w[MN], g, mw, ans, mem[MN][MW];

int slv(int id = 0, int ww = mw) {
	if (id == n or ww == 0)
		return 0;
	int &ret = mem[id][ww];
	if (ret == -1) {
		if (w[id] > ww)
			ret = slv(id + 1, ww);
		else
			ret = max(slv(id + 1, ww), v[id] + slv(id + 1, ww - w[id]));
	}
	return ret;
}

int main() {
	file();
	in(t);
	while (t--) {
		in(n), ans = 0, mem(mem, -1);
		for (int i = 0; i < n and in(v[i]) and in(w[i]); ++i)
			;
		in(g);
		for (int i = 0; i < g and in(mw); ++i)
			ans += slv();
		ot(ans);
	}
	return 0;
}
