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
#define otf(x) printf("%.2lf", x)
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
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
// constants
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
const int MN = 1e9 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

class Packet {
public:
	int ss, ee, id;
};
Packet nP(int x, int y, int z) {
	Packet p;
	p.id = x, p.ss = y, p.ee = z;
	return p;
}

int main() {
	file(); //TODO
	int n, m, ttt = 0;
	while (in(n) and in(m) and n and m) {
		int id, ss, ee, order[7] { 0, 1, 2, 3, 4, 5, 6 }, ndB = OO, s[7] { 0 };
		Packet seq[1002];
		for (int i = 1; i <= n and in(s[i]); ++i)
			;
		for (int i = 0; i < m and in(id) and in(ss) and in(ee); ++i)
			seq[i] = nP(id, ss, ee);
		do {
			int mxB = 0, cs = 0, cM = order[1], cB = 1, mIdx = 1;
			vi bytes[7];
			for (int i = 0; i < 7; ++i)
				for (int j = 0; j < s[i] + 4; ++j)
					bytes[i].pb(0);
			for (int i = 0; i < m; ++i) {
				Packet p = seq[i];
				for (int i = p.ss; i <= p.ee; ++i)
					bytes[p.id][i] = 1;
				cs += p.ee - p.ss + 1;
				while (mIdx <= n) {
					while (cB <= s[cM] and bytes[cM][cB])
						cB++, cs--;
					if (cB <= s[cM] or mIdx == n)
						break;
					cB = 1, cM = order[++mIdx];
				}
				mxB = max(mxB, cs);
			}
			ndB = min(ndB, mxB);
		} while (next_permutation(order + 1, order + n + 1));
		printf("Case %d: %d\n\n", ++ttt, ndB);
	}
	return 0;
}
