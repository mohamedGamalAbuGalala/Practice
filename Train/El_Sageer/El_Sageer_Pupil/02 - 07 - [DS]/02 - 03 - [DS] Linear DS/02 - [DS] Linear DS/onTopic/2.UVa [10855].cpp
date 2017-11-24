#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x)
#define sp() printf(" ")
#define ots(x) printf("%s ", x)
#define otc(x) printf("%c", x)
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

char sm[500][500], ar[500][500];

void find(int n, int m, int sum = 0) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int f = 1, k, l;
			for (k = 0; k < m and k + i < n and f; ++k)
				for (l = 0; l < m and j + l < n and f; ++l)
					if (ar[i + k][j + l] != sm[k][l])
						f = 0;
			if (f and l == m and k == m)
				sum++;
		}
	ot(sum);
}

void rotate(int n, int i = 0, int j = 0) {
	char tmp[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			tmp[i][j] = sm[n - j - 1][i];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			sm[i][j] = tmp[i][j];
}

int main() {
	file();
	int n, m;
	while (in(n), in(m) and n and m) {
		for (int i = 0; i < n and ins(ar[i]); ++i)
			;
		for (int i = 0; i < m and ins(sm[i]); ++i)
			;
		for (int i = 0; i < 4; ++i) {
			find(n, m);
			if (i < 3)
				sp();
			rotate(m);
		}
		ln();
	}
	return 0;
}
