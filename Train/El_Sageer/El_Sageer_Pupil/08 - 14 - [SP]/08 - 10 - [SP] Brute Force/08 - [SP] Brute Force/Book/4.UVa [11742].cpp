#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x)
#define sp() printf(" ")
#define ots(x) printf("%s", x)
#define otc(x) printf("%c", x)
#define ln() printf("\n")
#define otl(x) printf("%lld", x)
#define otf(x) printf("%.14lf", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(s) ((int)strlen(s))
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
const int MN = 2e6 + 1e2;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int find(int p, int arr[]) {
	int i;
	for (i = 0; i < 8; i++) {
		if (arr[i] == p)
			break;
	}
	return i;
}

int main() {
	file();
	int p[8] { 0, 1, 2, 3, 4, 5, 6, 7 }, a[22], b[22], c[22], m, n;
	while (in(n) and in(m) and (n or m)) {
		int res = 0;
		for (int i = 0; i < m and in(a[i]) and in(b[i]) and in(c[i]); ++i)
			;
		do {
			bool ans = 1;
			for (int i = 0; i < m; i++) {
				int pos1 = find(a[i], p), pos2 = find(b[i], p);
				if ((c[i] > 0 and abs(pos1 - pos2) > c[i])
						or (c[i] < 0 and abs(pos1 - pos2) < (-c[i]))) {
					ans = false;
					break;
				}
			}
			if (ans)
				res++;
		} while (next_permutation(p, p + n));
		ot(res), ln();
	}
	return 0;
}
