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
#define ff first
#define ss second
#define WH -1
#define BL 1

int N, M, x, v;

class SegmentTree {
private:
	int n, fV;
	vi A, st;
	int left(int p) {
		return p << 1;
	}
	int right(int p) {
		return (p << 1) | 1;
	}

	///  careful with dealing with A it's zero index but st is one index
	int getA(int idx) {
		return A[idx - 1];
	}
	void upA(int nV, int idx) {
		A[idx - 1] = nV;
	}

	int merge(int x, int y, int lvl) {
		if (N & 1) {
			if ((lvl & 1))
				return x | y;
			else
				return x ^ y;
		} else {
			if ((lvl & 1))
				return x ^ y;
			else
				return x | y;
		}
	}

	void build(int p, int L, int R, int lvl = 1) {
		if (L == R) {
			st[p] = getA(L);
			return;
		}
		int m = (L + R) >> 1, r = right(p), l = left(p);
		build(l, L, m, lvl + 1);
		build(r, m + 1, R, lvl + 1);
		st[p] = merge(st[l], st[r], lvl);
	}

	void update(int p, int L, int R, int idx, int val, int lvl = 1) {
		if (idx < L || idx > R)
			return;
		if (L == R and idx == R) {
			st[p] = val, upA(val, idx);
			return;
		}

		int m = (L + R) >> 1, r = right(p), l = left(p);
		update(l, L, m, idx, val, lvl + 1);
		update(r, m + 1, R, idx, val, lvl + 1);

		st[p] = merge(st[r], st[l], lvl);
	}

	int getRoot() {
		return st[1];
	}

public:
	SegmentTree(const vi &_A, int _fv) { // be carefull with fill value
		fV = _fv, A = _A;
		n = sz(A), st.assign(4 * n, 0), build(1, 1, n);
	}

	void up(int idx, int val) {
		update(1, 1, n, idx + 1, val);
	}

	int gR() {
		return getRoot();
	}
};

#define setBit(S, j) (S |= (1 << j))

int main() {
	file(); //TODO
	vi A;
	in(N), in(M);
	int NN = 0;
	setBit(NN, N);
	for (int i = 0; i < (NN) and in(x); A.pb(x), ++i)
		;
	SegmentTree st(A, 0);
	for (int i = 0; i < M and in(x) and in(v); ++i)
		st.up(x - 1, v), ot(st.gR()), ln();

	return 0;
}
