#include <bits/stdc++.h>
using namespace std;
// input handle
#define iln() scanf("\n")		//scan new line
#define in(n) scanf("%d",&n)	//scan int
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c ",&n)	//scan char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define inl(n) scanf("%lld",&n)	//scan long long int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define otc(x) printf("%c", x)	//output char
#define ln() printf("\n")		//output new line
#define otl(x) printf("%lld", x)//output long long int
#define otf(x) printf("%.2lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e6 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int main() {
	file(); //TODO
	int n, m, vC[102] { 0 }, arr[102], x, nCsm = 0;
	in(n), in(m);
	for (int i = 0; i < n and in(arr[i]); ++i)
		;
	vi unC, C;
	for (int i = 0; i < m and in(x); ++i)
		vC[x - 1] = 1, C.pb(arr[x - 1]);

	for (int i = 0; i < n; ++i)
		if (!vC[i])
			unC.pb(arr[i]), nCsm += arr[i];
	sort(all(C));
	lli ret1 = nCsm, ret2 = ret1;
	for (int i = 0; i < sz(C); ++i)
		if (ret1 > C[i])
			ret1 += ret1;
		else
			ret1 += C[i];
	for (int i = sz(C) - 1; i >= 0; --i)
		if (ret2 > C[i])
			ret2 += ret2;
		else
			ret2 += C[i];
	otl(max(ret1, ret2));
	return 0;
}
