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
	file();
	int t, n;
	in(t);
	while (t-- and in(n)) {
		int ar[MN] { 0 }, l, h, idx = 1, Q, q;
		map<int, string> mid;
		string s;
		for (int i = 0; i < n and cin >> s and in(l) and in(h);
				mid[idx++] = s, ++i)
			for (int j = l; j <= h; ++j)
				if (ar[j])
					ar[j] = -1;
				else
					ar[j] = idx;
		in(Q);
		while (Q-- and in(q))
			if (ar[q] and ar[q] != -1)
				cout << mid[ar[q]], ln();
			else
				puts("UNDETERMINED");
		if (t)
			ln();
	}
	return 0;
}
