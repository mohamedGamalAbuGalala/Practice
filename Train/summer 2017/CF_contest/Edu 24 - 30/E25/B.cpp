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
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
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
const int MN = 1e7 + 1;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int n = 10;
char a[11][11];
int dx[] = { 0, 1, 1, 1 };
int dy[] = { 1, 1, 0, -1 };

bool val(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
	file();

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 4; k++) {
				int cnt = 0;
				if (val(i + 4 * dx[k], j + 4 * dy[k]))
					for (int o = 0; o < 5; o++) {
						int ii = i + dx[k] * o;
						int jj = j + dy[k] * o;
						if (a[ii][jj] == 'X')
							cnt++;
						if (a[ii][jj] == 'O')
							cnt -= 10;
					}
				if (cnt == 4)
					return puts("YES"), 0;
			}
	puts("NO");
	return 0;
}
