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
const int MN = 1e7 + 1;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int t[MN];

int main() {
	file();
	int n, tst = 0;
	while (in(n) and n) {
		ots("Scenario #"), ot(++tst), ln();
		queue<int> ar[n], qt;
		int nn, x, Qt[n] { 0 };
		for (int i = 0; i < n and in(nn); ++i)
			for (int j = 0; j < nn and in(x); t[x] = i, ++j)
				;
		string s, ENQ = "ENQUEUE", DEQ = "DEQUEUE", STOP = "STOP";
		while (cin >> s and s != STOP) {
			if (s == ENQ) {
				in(x);
				if (!Qt[t[x]])
					Qt[t[x]] = 1, qt.push(t[x]);
				ar[t[x]].push(x);
			} else if (s == DEQ) {
				ot(ar[qt.front()].front()), ln(), ar[qt.front()].pop();
				if (!sz(ar[qt.front()]))
					Qt[qt.front()] = 0, qt.pop();
			}
		}
		ln();
	}
	return 0;
}
