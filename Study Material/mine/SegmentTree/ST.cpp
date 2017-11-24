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
#define f first
#define s second
#define WH -1
#define BL 1

class SegmentTree {
private:
	int n, fV;
	vi st, A;
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

	int merge(int x, int y) {
		return min(x, y);
	}

	void build(int p, int L, int R) {
		if (L == R) {
			st[p] = getA(L);
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
			st[p] = val, upA(val, idx);
			return;
		}

		int m = (L + R) >> 1, r = right(p), l = left(p);
		update(l, L, m, idx, val);
		update(r, m + 1, R, idx, val);

		st[p] = merge(st[r], st[l]);
	}

	int getRoot() {
		return st[1];
	}

public:
	SegmentTree(const vi &_A, int _fv) {	// be carefull with fill value
		fV = _fv, A = _A;
		n = sz(A), st.assign(4 * n, 0), build(1, 1, n);
	}

	int q(int i, int j) {
		return query(1, 1, n, i + 1, j + 1);
	}

	void up(int idx, int val) {
		update(1, 1, n, idx + 1, val);
	}

	int gR() {
		return getRoot();
	}
};

int main() {
	file(); //TODO
	int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
	vi A(arr, arr + 7);
	SegmentTree st(A, OO);	// U deal from main as zero index

	printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
	printf("              A is {18,17,13,19,15, 11,20}\n");
	printf("RMQ(1, 3) = %d\n", st.q(1, 3));
	printf("RMQ(4, 6) = %d\n", st.q(4, 6));
	printf("RMQ(3, 4) = %d\n", st.q(3, 4));
	printf("RMQ(0, 0) = %d\n", st.q(0, 0));
	printf("RMQ(0, 1) = %d\n", st.q(0, 1));
	printf("RMQ(0, 6) = %d\n", st.q(0, 6));

	printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
	printf("Now, modify A into {18,17,13,19,15,100,20}\n");
	st.up(5, 100);
	printf("These values do not change\n");
	printf("RMQ(1, 3) = %d\n", st.q(1, 3));
	printf("RMQ(3, 4) = %d\n", st.q(3, 4));
	printf("RMQ(0, 0) = %d\n", st.q(0, 0));
	printf("RMQ(0, 1) = %d\n", st.q(0, 1));
	printf("These values change\n");
	printf("RMQ(0, 6) = %d\n", st.q(0, 6));
	printf("RMQ(4, 6) = %d\n", st.q(4, 6));
	printf("RMQ(4, 5) = %d\n", st.q(4, 5));

	return 0;
}
