#include <bits/stdc++.h>
using namespace std;
// input handle
#define sp() printf(" ")
#define ln() printf("\n")
#define in(n) scanf("%d",&n)
#define ot(x) printf("%d", x)
#define ins(n) scanf("%s",n)
#define ots(x) printf("%s ", x)
#define inc(n) scanf("%c",&n)
#define otc(x) printf("%c", x)
#define inf(n) scanf("%lf",&n)
#define otf(x) printf("%.2lf ", x)
#define inl(n) scanf("%lld",&n)
#define otl(x) printf("%lld ", x)
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
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e4 + 1e5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int main() {
	file();
	int n;
	while (in(n) and n) {
		int ar[MN], ans = 0;
		for (int i = 0; i < n and in(ar[i]); ++i)
			;
		for (int i = 0; i < n; ++i) {
			int l = i - 1, r = i + 1;
			if (i == 0)
				l = n - 1;
			if (i == n - 1)
				r = 0;
			if ((ar[l] < ar[i] and ar[i] > ar[r])
					or (ar[l] > ar[i] and ar[i] < ar[r]))
				ans++;
		}
		ot(ans), ln();
	}
	return 0;
}
