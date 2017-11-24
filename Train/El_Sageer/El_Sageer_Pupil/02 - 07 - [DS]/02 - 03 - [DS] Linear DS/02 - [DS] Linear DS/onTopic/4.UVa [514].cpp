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

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define toggleBit(S, j) (S ^= (1 << j))

int main() {
	file();
	int n;
	while (in(n) and n) {
		int x;
		while (in(x) and x) {
			vi inp;
			bool v[1001] { 0 };
			stack<int> s;
			inp.pb(x);
			for (int i = 0; i < n - 1 and in(x); ++i)
				inp.pb(x);
			for (int i = 0; i < sz(inp); ++i) {
				for (int j = 1; j <= inp[i]; ++j)
					if (!v[j])
						s.push(j), v[j] = 1;
				if (s.top() == inp[i])
					s.pop();
			}
			if (sz(s))
				puts("No");
			else
				puts("Yes");
		}
		ln(), n = 0;
	}
	return 0;
}
