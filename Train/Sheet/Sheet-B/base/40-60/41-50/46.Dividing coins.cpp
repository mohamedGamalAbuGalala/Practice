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

int ar[101], n, mem[100][50000], t, res, sm;

int slv(int idx = 0, int r1 = 0) {
	if(sm - r1 - r1 < 0)
		return OO;
	if (idx >= n)
		return abs(sm - r1 - r1);
	int &ret = mem[idx][r1];
	if (ret == -1)
		ret = min(slv(idx + 1, r1 + ar[idx]), slv(idx + 1, r1));
	return ret;
}

int main() {
	file();
	in(t);
	while (t--) {
		in(n), mem(mem, -1), res = OO, sm = 0;
		for (int i = 0; i < n and in(ar[i]); sm += ar[i], ++i)
			;
		ot(slv());
	}
	return 0;
}
