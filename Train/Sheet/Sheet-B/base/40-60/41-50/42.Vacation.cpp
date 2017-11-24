#include <bits/stdc++.h>
using namespace std;
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
#define all(v) ((v).begin(),(v).end())
#define sz(v) ((int)((v).size()))
#define cl(v,d) memset(v,d,sizeof(v))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e3 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;

string a, b;
int t, mem[101][101];

int slv(int i = 0, int j = 0) {
	if (i == sz(a) or j == sz(b))
		return 0;
	int &ret = mem[i][j];
	if (mem[i][j] == -1) {
		if (a[i] == b[j])
			ret = 1 + slv(i + 1, j + 1);
		else
			ret = max(slv(i + 1, j), slv(i, j + 1));
	}
	return ret;
}

int main() {
	file();
	while (getline(cin, a) and getline(cin, b) and a != "#") {
		mem(mem, -1);
		printf("Case #%d: you can visit at most %d cities.\n", ++t, slv());
	}
	return 0;
}
