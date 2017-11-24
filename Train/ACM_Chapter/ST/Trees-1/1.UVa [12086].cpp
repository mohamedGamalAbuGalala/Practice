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
	freopen("ot.txt", "w", stdout);
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

class SegmentTree {         // the segment tree is stored like a heap array
private:
	int n, fV;
	vi st, arr;
	int left(int p) {
		return p << 1;
	}
	int right(int p) {
		return (p << 1) + 1;
	}

	int merge(int x, int y) {
		return x + y;
	}

	void build(int p, int L, int R) {
		if (L == R) {
			st[p] = arr[L];
			return;
		}
		int m = (L + R) >> 1, r = right(p), l = left(p);
		build(l, L, m);
		build(r, m + 1, R);
		st[p] = merge(st[l], st[r]);
	}

	int query(int p, int L, int R, int i, int j) {
		if (i > R or j < L)
			return fV;
		if (L >= i and R <= j)
			return st[p];
		int m = (L + R) >> 1, r = right(p), l = left(p);
		int q1 = query(l, L, m, i, j);
		int q2 = query(r, m + 1, R, i, j);

		return merge(q1, q2);
	}
	void update(int p, int L, int R, int idx, int val) {
		if (idx < L || idx > R)
			return;
		if (L == R and idx == R) {
			st[p] = val, arr[idx] = val;
			return;
		}

		int m = (L + R) >> 1, r = right(p), l = left(p);

		update(l, L, m, idx, val);
		update(r, m + 1, R, idx, val);

		st[p] = merge(st[r], st[l]);
	}

public:
	SegmentTree(const vi &_A, int _fv) {
		arr.pb(0), fV = _fv;
		for (auto aa : _A)
			arr.pb(aa);
		n = sz(arr), st.assign(4 * n, 0), build(1, 0, n);
	}

	int q(int i, int j) {
		return query(1, 0, n, i, j);
	}

	void up(int idx, int val) {
		update(1, 0, n, idx, val);
	}
};

int main() {
	file(); //TODO
	int N, x, tt = 0;
	vi A;
	while (1) {
		in(N);
		if (!N)
			break;
		if (tt)
			ln();
		A.clear(), printf("Case %d:\n", ++tt);
		for (int i = 0; i < N and in(x); A.pb(x), ++i)
			;
		SegmentTree st(A, 0);
		char ch[4];
		int x1, x2;
		while (ins(ch) and ch[0] != 'E' and in(x1) and in(x2))
			if (ch[0] == 'M')
				ot(st.q(x1, x2)), ln();
			else
				st.up(x1, x2);
	}
	return 0;
}
