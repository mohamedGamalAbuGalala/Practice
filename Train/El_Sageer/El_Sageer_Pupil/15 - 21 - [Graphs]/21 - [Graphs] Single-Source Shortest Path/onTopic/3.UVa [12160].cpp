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
#define otf(x) printf("%.9lf", x)// output double/float with 0.00
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
const int MN = 1e5 + 1e2;
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
#define ff first
#define ss second
#define WH -1
#define BL 1

vi vs, but;

int Bfs(int s, int d, int sz = 1, int cur = 0) {
	queue<int> q;
	q.push(s), vs[s] = 1;
	for (int cos = 0; sz(q); cos++, sz = sz(q))
		while (sz--) {
			cur = q.front(), q.pop();
			if (cur == d)
				return ot(cos), ln(), 0;
			for (auto x : but) {
				int toP = (x + cur) % 10000;
				if (!vs[toP])
					q.push(toP), vs[toP] = 1;
			}
		}
	return puts("Permanently Locked"), 0;
}
int main() {
	file(); //TODO
	int S, D, N, tt = 0;
	while (in(S) and in(D) and in(N) and (S or D or N)) {
		vs.assign(10004, 0), but.clear();
		for (int i = 0, x; i < N and in(x); but.pb(x), ++i)
			;
		printf("Case %d: ", ++tt), Bfs(S, D);
	}
	return 0;
}
