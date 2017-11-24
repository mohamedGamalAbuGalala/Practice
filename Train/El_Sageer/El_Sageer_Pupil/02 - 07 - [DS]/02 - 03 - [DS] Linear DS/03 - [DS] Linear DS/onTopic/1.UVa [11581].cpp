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

char ar[500][3][3];

int ti[] { 0, 0, 1, -1 };
int tj[] { 1, -1, 0, 0 };

bool done(int l) {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (ar[l][i][j] == '1')
				return 0;
	return 1;
}

int f(int l) {
	if (done(l))
		return -1;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			int sm = 0;
			for (int k = 0; k < 4; ++k) {
				int tr = i + ti[k], tc = j + tj[k];
				if (tr < 3 and tr > -1 and tc < 3 and tc > -1
						and ar[l][tr][tc] == '1')
					sm++;
			}
			ar[l + 1][i][j] = ((sm & 1) ? '1' : '0');
		}
	return 1 + f(l + 1);
}

int main() {
	file();
	int t;
	in(t), iln();
	while (t--) {
		iln();
		for (int i = 0; i < 3 and ins(ar[0][i]); ++i)
			;
		ot(f(0)), ln();
	}
	return 0;
}
