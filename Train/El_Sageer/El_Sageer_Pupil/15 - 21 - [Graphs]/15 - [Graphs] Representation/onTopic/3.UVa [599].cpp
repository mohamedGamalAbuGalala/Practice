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

//#define f first
//#define s second

void split(const string &s, const char* delim, vector<string> & v) {
	// to avoid modifying original string
	// first duplicate the original string and return a char pointer then free the memory
	char * dup = strdup(s.c_str());
	char * token = strtok(dup, delim);
	while (token != NULL) {
		v.push_back(string(token));
		// the call is treated as a subsequent calls to strtok:
		// the function continues from where it left in previous invocation
		token = strtok(NULL, delim);
	}
	free(dup);
}

vi adj[26];
int v[26];

int BFS(int s, int sz = 1, int cur = 0, int ret = 0) {
	queue<int> q;
	q.push(s), v[s] = 1;
	for (; sz(q); sz = sz(q))
		while (sz--) {
			cur = q.front(), q.pop(), ret++;
			for (int it = 0; it < sz(adj[cur]); it++)
				if (!v[adj[cur][it]])
					v[adj[cur][it]] = 1, q.push(adj[cur][it]);
		}
	return ret;
}

int main() {
	file(); // TODO
	int t;
	in(t), getchar();
	while (t--) {
		for (int i = 0; i < 26; ++i)
			adj[i].clear(), v[i] = 0;
		string s;
		while (getline(cin, s) and s[0] != '*') {
			vector<string> sp;
			split(s, "(,)", sp);
			adj[sp[0][0] - 'A'].pb(sp[1][0] - 'A'), adj[sp[1][0] - 'A'].pb(
					sp[0][0] - 'A');
		}
		getline(cin, s);
		vector<string> sp;
		split(s, ",", sp);
		int tr = 0, ac = 0, res;
		for (auto it : sp)
			if (!v[it[0] - 'A']) {
				res = BFS((it[0] - 'A'));
				if (res == 1)
					ac++;
				else
					tr++;
			}
		printf("There are %d tree(s) and %d acorn(s).\n", tr, ac);
	}
	return 0;
}
