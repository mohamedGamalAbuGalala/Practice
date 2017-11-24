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
#define otf(x) printf("%.9lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define max3(a,b,c) max(a , max(b , c))
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
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

//#define f first
//#define s second

void s() {
	string str;
	cin >> str;
	int type = 1,pos;
	if (str[0] == 'R' && isdigit(str[1]))
		for (int i = 2; i < sz(str); i++)
			if (str[i] == 'C')
				type = 0,pos = i;
	int row = 0, col = 0;
	string column;
	if (type == 1) {
		int i = 0;
		for (; !isdigit(str[i]); i++)
			col *= 26,col += str[i] - 'A' + 1;
		for (; i < sz(str); i++)
			row *= 10,row += str[i] - '1' + 1;
		cout << 'R' << row << 'C' << col << endl;
	} else {
		int i = 1;
		for (; i < pos; i++)
			row *= 10,row += str[i] - '1' + 1;
		i++;
		for (; i < sz(str); i++)
			col *= 10,col += str[i] - '1' + 1;
		while (col != 0)
			col--,column = char(col % 26 + 'A') + column,col /= 26;
		cout << column << row << endl;
	}
}

int main() {
	file(); // TODO
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		s();
	return 0;
}
