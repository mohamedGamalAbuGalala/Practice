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
	int l, r, m;
};
Packet nP(int x, int y, int z) {
	Packet p;
	p.m = x, p.l = y, p.r = z;
	return p;
}
int mn, N, M, size[6], order[6];
Packet seq[1002];

int simulate() {
	int curSize = 0, minSize = 0, msgIdx = 0, curMsg = order[0], curByte = 0;
	vi bytes[N];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < size[i]; ++j)
			bytes[i].pb(0);
//		 = vi(size[i]);
	for (int f = 0; f < M; f++) {
		Packet p = seq[f];
		for (int i = p.l; i <= p.r; ++i)
			bytes[p.m][i] = 1;
		curSize += p.r - p.l + 1;
		while (msgIdx < N) {
			while (curByte < sz(bytes[curMsg]) && bytes[curMsg][curByte] == 1)
				++curByte, --curSize;
			if (curByte != sz(bytes[curMsg]) || msgIdx == N - 1)
				break;
			curByte = 0;
			curMsg = order[++msgIdx];
		}
		minSize = max(minSize, curSize);
	}
	return minSize;
}

void findMin(int idx, int msk) {
	if (idx == N) {
		mn = min(mn, simulate());
		return;
	}
	for (int i = 0; i < N; ++i)
		if ((msk & 1 << i) == 0) {
			order[idx] = i;
			findMin(idx + 1, msk | 1 << i);
		}
}
int main() {
	file(); //TODO
	int tc = 1, id, ss, ee;
	while (true) {
		in(N), in(M);
		if (N == 0)
			break;
		mem(size, 0);
		for (int i = 0; i < N; ++i)
			in(size[i]);
		mem(seq, 0);
		for (int i = 0; i < M and in(id) and in(ss) and in(ee); ++i)
			seq[i] = nP(id - 1, ss - 1, ee - 1);
		mn = OO;
		mem(order, 0);
		findMin(0, 0);
		printf("Case %d: %d\n\n", tc++, mn);
	}
	return 0;
}
