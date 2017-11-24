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
	return 0;
	/*
	 I love CS3233 Competitive Programming. i also love AlGoRiThM
	 */
	string ss;
	getline(cin, ss);
	vector<string> tkns, ans;
	map<string, int> mpC;
	int mx = 0;
	transform(all(ss), ss.begin(), ::tolower), split(ss, " ,.", tkns);
	for (auto s : tkns) {
		mpC[s]++;
		if (mpC[s] > mx)
			ans.clear(), ans.pb(s), mx = mpC[s];
		else if (mpC[s] == mx)
			ans.pb(s);
	}
	ot(mx), puts(" is the max");
	for (auto s : ans)
		cout << s, sp();
	return 0;
	/*
	 I love CS3233 Competitive Programming. i also love AlGoRiThM
	 */
	string inp;
	map<char, int> vow;
	int cons = 0, v = 0;
	vow['a'] = 1, vow['e'] = 1, vow['i'] = 1, vow['o'] = 1, vow['u'] = 1;
	getline(cin, inp), transform(all(inp), inp.begin(), ::tolower);
	for (auto ch : inp)
		if (vow[ch])
			v++;
		else
			cons++;
	ot(v), sp(), ot(cons), ln();
	vector<string> tokkens;
	split(inp, " ,.", tokkens), sort(all(tokkens)), cout << tokkens[0];
	return 0;
	/*
	 I love CS3233 Competitive Programming. i also love AlGoRiThM
	 love
	 */
	string line, tF;
	getline(cin, line), cin >> tF;
	auto id = line.find(tF);
	while (id != string::npos)
		ot((int)id), id = line.find(tF, id + 1), sp();
	ln(), line.replace(line.find(tF), tF.length(), "replaced correctly"), cout
			<< line;
	return 0;
	/*
	 I love CS3233 Competitive
	 Programming. i also love
	 AlGoRiThM
	 .......you must stop after reading this line as it starts with 7 dots
	 after the first input block, there will be one loooooooooooong line...
	 */
	string lin, Lstring;
	while (getline(cin, lin) and lin.substr(0, 7) != ".......")
		if (sz(Lstring))
			Lstring += " " + lin;
		else
			Lstring = lin;
	cout << Lstring;
	return 0;
}
