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
#define otf(x) printf("%.6lf", x)
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
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

void MergeWithCountInversions(vi& v, int p, int q, int r, int& cnt) {
	int n1 = q - p, n2 = r - q;
	vi L, R;
	for (int i = 0; i < n1; ++i)
		L.pb(v[p + i]);
	for (int i = 0; i < n2; ++i)
		R.pb(v[q + i]);
	L.pb(OO), R.pb(OO);
	int i = 0, j = 0;
	for (int k = p; k < r; ++k)
		if (L[i] <= R[j])
			v[k] = L[i], i += 1;
		else
			v[k] = R[j], j += 1, cnt += n1 - i;
}

void MergeSort(vi& v, int p, int r, int& cnt) {
	if (p >= r - 1)
		return;
	int q = (p + r) >> 1;
	MergeSort(v, p, q, cnt);
	MergeSort(v, q, r, cnt);
	MergeWithCountInversions(v, p, q, r, cnt);
}

int main() {
	file();
	int n, x;
	while (in(n) == 1) {
		vi v;
		for (int i = 0; i < n and in(x); v.pb(x), ++i)
			;
		int cnt = 0;
		MergeSort(v, 0, (int) v.size(), cnt);
		printf("Minimum exchange operations : %d\n", cnt);
	}
	return 0;
}
