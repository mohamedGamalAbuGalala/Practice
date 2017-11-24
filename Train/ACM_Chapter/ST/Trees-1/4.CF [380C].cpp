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
struct node {
	int a, b, c;
};

node nodeN;
class SegmentTree {
private:
	int n, fV;
	vector<node> st;
	vi A;
	int left(int p) {
		return p << 1;
	}
	int right(int p) {
		return (p << 1) + 1;
	}

	///  careful with dealing with A it's zero index but st is one index
	int getA(int idx) {
		return A[idx - 1];
	}
	void upA(int nV, int idx) {
		A[idx - 1] = nV;
	}

	node merge(node x, node y) {
		int t = min(x.b, y.c);
		return node { (x.a + y.a + t), (x.b + y.b - t), (x.c + y.c - t) };
	}

	void build(int p, int L, int R) {
		if (L == R) {
			st[p] = node { 0, (getA(L) == 1), (getA(L) == -1) };
			return;
		}
		int m = (L + R) >> 1, r = right(p), l = left(p);
		build(l, L, m);
		build(r, m + 1, R);
		st[p] = merge(st[l], st[r]);
	}

	node query(int p, int L, int R, int i, int j) {
		if (i > R or j < L)
			return nodeN;
		if (L >= i and R <= j)
			return st[p];
		int m = (L + R) >> 1, r = right(p), l = left(p);
		node q1 = query(l, L, m, i, j);
		node q2 = query(r, m + 1, R, i, j);

		return merge(q1, q2);
	}

public:
	SegmentTree(const vi &_A, int _fv) {	// be carefull with fill value
		fV = _fv, A = _A;
		n = sz(A), st.assign(4 * n, node { 0, 0, 0 }), build(1, 1, n);
	}

	node q(int i, int j) {
		return query(1, 1, n, i + 1, j + 1);
	}
};

int main() {
	file(); //TODO
	vi A;
	string ss;
	cin >> ss;
	for (auto xx : ss)
		if (xx == '(')
			A.pb(1);
		else
			A.pb(-1);
	SegmentTree st(A, 0);
	int Q, l, r;
	in(Q);
	while (Q-- and in(l) and in(r)) {
		ot(2*st.q(l-1,r-1).a), ln();
	}
	return 0;
}
