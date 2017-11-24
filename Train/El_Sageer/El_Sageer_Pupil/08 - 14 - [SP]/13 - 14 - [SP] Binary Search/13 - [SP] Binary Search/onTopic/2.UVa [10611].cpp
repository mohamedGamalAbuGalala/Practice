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
#define otf(x) printf("%.3lf", x)// output double/float with 0.00
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

int main() {
	file(); // TODO
	int n, m;
	cin >> n;
	vector<unsigned int> ar;
	for (int i = 0; i < n; ++i) {
		unsigned int tmp;
		cin >> tmp;
		ar.pb(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		unsigned int tmp;
		cin >> tmp;
		int l, r;
		if (tmp > ar[n - 1]) {
			l = lower_bound(ar.begin(), ar.end(), ar[n - 1]) - (ar.begin());
			r = -1;
			cout << ar[l] << " " << "X" << endl;
			continue;
		} else if (tmp == ar[n - 1]) {
			l = lower_bound(ar.begin(), ar.end(), ar[n - 1]) - (ar.begin());
			r = -1;
			cout << ar[l - 1] << " " << "X" << endl;
			continue;
		} else if (tmp <= ar[0]) {
			l = -1;
			r = upper_bound(ar.begin(), ar.end(), tmp) - (ar.begin());
			cout << "X" << " " << ar[r] << endl;
			continue;
		} else {
			l = lower_bound(ar.begin(), ar.end(), tmp) - (ar.begin());
			r = upper_bound(ar.begin(), ar.end(), tmp) - (ar.begin());
		}
		cout << ((ar[l] == tmp || l == r) ? ar[l - 1] : ar[l]) << " " << ar[r]
				<< endl;
	}
	return 0;
}
