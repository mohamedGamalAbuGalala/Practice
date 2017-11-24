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

char hexaaa[] { 'A', 'B', 'C', 'D', 'E', 'F' };

string itoa(lli n, int s) {
	string ret = "";
	while (n != 0) {
		char in = n % s + '0';
		if (in > '9')
			in = hexaaa[(in - ('9' + 1))];
		ret = in + ret;
		n /= s;
	}
	return ret;
}

int main() {
	file(); //TODO
	char ss[50];
	int n, m;
	while (ins(ss) + in(n) + in(m) == 3) {
		int i, l = ssz(ss);
		lli dec = 0, j = 1;
		for (i = l - 1; i >= 0; j *= n, i--)
			if (ss[i] <= '9')
				dec += (ss[i] - '0') * j;
			else
				dec += (ss[i] - 'A' + 10) * j;
		string ans = itoa(dec, m);
		if (sz(ans) > 7) {
			puts("  ERROR");
			continue;
		} else if (!sz(ans))
			ans = "0";
		for (int i = 6; i >= sz(ans); --i)
			sp();
		for (auto ch : ans)
			otc(ch);
		ln();
	}
	return 0;
}
