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
#define otf(x) printf("%.12lf", x)// output double/float with 0.00
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ssz(s) ((int)strlen(s))		// eg... char s[10];  ssz(s)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define max3(a,b,c) max(a , max(b , c))
#define min3(a,b,c) min(a , min(b , c))
#define ff first
#define ss second
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
const int MN = 1e6 + 1e1;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)

void split(const string &s, const char* delim, vector<string> & v) {
	char * dup = strdup(s.c_str());
	char * token = strtok(dup, delim);
	while (token != NULL)
		v.push_back(string(token)), token = strtok(NULL, delim);
	free(dup);
}

int main() {
	file(); //TODO
	int n;
	vector<bool> ib;
	bool inB = 0;
	string s;
	cin >> n >> s;
	forr(i,0,sz(s))
	{
		if (s[i] == '(')
			inB = 1;
		else if (s[i] == ')')
			inB = 0;
		if (isalpha(s[i])) {
			if (inB)
				ib.pb(1);
			else
				ib.pb(0);
			while (isalpha(s[i]))
				i++;
			i--;
		}
	}
	vector<string> sp;
	int wb = 0, mxS = 0;
	split(s, "_()", sp);
	forr(i,0,sz(sp))
		if (ib[i])
			wb++;
		else
			mxS = max(mxS, sz(sp[i]));
	ot(mxS), sp(), ot(wb);
	return 0;
}
