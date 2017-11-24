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

int C[] { 50, 25, 10, 5, 1 }, mem[5][7500];

int slv(int t, int v) {
	if (v < 0 or t == 5)
		return 0;
	if (!v)
		return 1;
	int &ret = mem[t][v];
	if (ret == -1)
		ret = slv(t + 1, v) + slv(t, v - C[t]);
	return ret;
}

int main() {
	file();
	int n;
	mem(mem, -1);
	while (scanf("%d", &n) != EOF)
		ot(slv(0, n));
	return 0;
}
