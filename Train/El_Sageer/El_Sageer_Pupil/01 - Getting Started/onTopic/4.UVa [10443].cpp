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

int n, m, d;
vector<string> v(101);
int di[] = { 1, -1, 0, 0 }, I, J;
int dj[] = { 0, 0, 1, -1 };

char f(int a, int b) {
	if (v[a][b] == 'R') {
		for (int i = 0; i < 4; i++) {
			I = a + di[i];
			J = b + dj[i];
			if (I >= 0 && I < n && J >= 0 && J < m && v[I][J] == 'P')
				return 'P';
		}
		return 'R';
	} else if (v[a][b] == 'P') {
		for (int i = 0; i < 4; i++) {
			I = a + di[i];
			J = b + dj[i];
			if (I >= 0 && I < n && J >= 0 && J < m && v[I][J] == 'S')
				return 'S';
		}
		return 'P';
	} else {
		for (int i = 0; i < 4; i++) {
			I = a + di[i];
			J = b + dj[i];
			if (I >= 0 && I < n && J >= 0 && J < m && v[I][J] == 'R')
				return 'R';
		}
		return 'S';
	}
}
int main() {
	file();
	int t;
	in(t);
	while (t--) {
		vector<string> ax;
		in(n), in(m), in(d);
		for (int i = 0; i < n and cin >> (v[i]); ++i)
			;
		for (int i = 0; i < d; ++i) {
			ax.clear();
			for (int j = 0; j < n; j++) {
				string s = "";
				for (int k = 0; k < m; k++)
					s += f(j, k);
				ax.push_back(s);
			}
			v = ax;
		}
		for (int i = 0; i < n; ++i)
			cout << v[i], ln();
		if (t)
			ln();
	}
	return 0;
}
