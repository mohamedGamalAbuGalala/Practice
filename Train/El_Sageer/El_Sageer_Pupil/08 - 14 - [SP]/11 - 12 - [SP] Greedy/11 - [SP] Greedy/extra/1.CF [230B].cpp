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
#define otf(x) printf("%.2lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
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
const int MN = 1e6 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

lli _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>

void sieve(lli upperbound) {         // create list of primes in [0..upperbound]
	_sieve_size = upperbound + 1;                 // add 1 to include upperbound
	bs.set();                                               // set all bits to 1
	bs[0] = bs[1] = 0;                                   // except index 0 and 1
	for (lli i = 2; i <= _sieve_size; i++)
		if (bs[i])
			for (lli j = i * i; j <= _sieve_size; j += i)
				bs[j] = 0;
}                                           // call this method in main method

bool isPrime(lli N) {
	return bs[N];
}

int main() {
	file(); //TODO
	sieve(1001000);                      // can go up to 10^7 (need few seconds)
	lli n, x;
	inl(n);
	for (lli i = 0; i < n and inl(x); ++i) {
		lli sq = sqrt(x);
		if (sq * sq == x) {
			if (isPrime(sq))
				puts("YES");
			else
				puts("NO");
		} else
			puts("NO");

	}
	return 0;
}
