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

int _sieve_size;
bitset<100> bs;
void sieve(int upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= _sieve_size; i++)
		if (bs[i])
			for (int j = i * i; j <= _sieve_size; j += i)
				bs[j] = 0;
}
bool isPrime(int N) {
	if (N <= _sieve_size)
		return bs[N];
	return true;
}

int ar[17], n, t = 0, id = 1 << 1;

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))

void bT(int c) {
	if (c == n) {
		if (!isPrime(ar[0] + ar[n - 1]))
			return;
		ot(1);
		for (int i = 1; i < n; ++i)
			sp(), ot(ar[i]);
		ln();
		return;
	}
	for (int i = 2; i <= n; ++i)
		if (!isOn(id, i) and isPrime(ar[c - 1] + i))
			ar[c] = i, setBit(id, i), bT(c + 1), clearBit(id, i);
}

int main() {
	file();
	sieve(50), ar[0] = 1;
	in(n);
	while (1) {
		printf("Case %d:\n", ++t);
		if (!(n & 1) or n == 1)
			bT(1);
		if (in(n) == 1)
			ln();
		else
			break;
	}
	return 0;
}
