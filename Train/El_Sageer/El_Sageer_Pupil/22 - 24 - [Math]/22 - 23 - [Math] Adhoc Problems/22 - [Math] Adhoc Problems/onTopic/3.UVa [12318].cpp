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
#define otf(x) printf("%.0lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define max3(a,b,c) max(a , max(b , c))
#define min3(a,b,c) min(a , min(b , c))
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
const int MN = 1e7 + 1e1;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
#define f first
#define s second
#define WH -1
#define BL 1

int N, M, K, a[15];
set<lli> s;

int evaluate(int k, int x, int n) {
	int res = 0;
	while (k >= 0)
		res = (int) ((a[k--] + (lli) 1 * res * x) % n);
	return res;
}

lli P(int x) {
	lli ans = 0, pow = 1;
	for (int i = 0; i <= K; i++) {
		if (a[i])
			ans = (ans + a[i] * pow) % (N + 1);
		pow = (pow * x) % (N + 1);
	}
	return ans;
}

int main() {
	file(); //TODO
	while (in(N) and in(M) and (N or M)) {
		in(K), s.clear();
		for (int i = 0; i <= K and in(a[i]); ++i)
			;
		for (int m = 0; m <= M; ++m) {
			s.insert(P(m));
//			//			int res = 0, pow = 1;
////			for (int i = K; i >= 0;
////					pow *= m, pow %= (N + 1), res %= (N + 1), --i)
////				if (a[i])
////					res += (a[i] * pow);
////			s.insert(res);
//			s.insert(evaluate(K, m, N + 1));
		}
		ot(sz(s)), ln();
	}
	return 0;
}
