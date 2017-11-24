#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ots(x) printf("%s ", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(ss) ((int)strlen(s))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
// constants
const int MN = 1e6 + 1e5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int main() {
	file();
	int n, ar[101], i = 0, dec = 0 ,stab = 0;
	in(n);
	for (int i = 0; i < n and in(ar[i]); ++i)
		if (i > 0 and ar[i] == ar[i - 1])
			stab = 1;
	while (i < n - 1 and ar[i + 1] > ar[i])
		i++;
	while (i < n - 1 and ar[i + 1] == ar[i])
		i++;
	while (i < n - 1 and ar[i + 1] < ar[i])
		i++;
	if (i == n - 1) {
		if (dec and ar[n - 1] >= ar[n - 2])
			return ots("no");
		puts("yes");

	} else
		puts("no");
	return 0;
}
