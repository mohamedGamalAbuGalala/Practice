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

int J[55][5], d, n, g, fc, l;

void chg(int i, double &t, double f) {
	for (int j = 0, don = 0; j < 4 and !don; ++j)
		if (J[i][j]) {
			if (j == 0)
				fc = J[i][j], don = 1;
			else if (j == 1)
				l += J[i][j], don = 1;
			else if (j == 2 and t > 0)
				t = f, don = 1;
			else
				l = 0, don = 1;
		}
}

bool can(double f) {
	double t = f;
	l = 0, fc = J[0][0];
	for (int i = 1; i <= g; ++i) {
		t -= ((((double) J[i][4] - (double) J[i - 1][4]) / 100.00)
				* ((double) fc))
				+ l * ((double) J[i][4] - (double) J[i - 1][4]);
		if (J[i][4] == J[i + 1][4]) {
			int cd = J[i][4];
			while (J[i][4] == cd)
				chg(i, t, f), i++;
			i--;
		} else
			chg(i, t, f);
	}
	return t >= 0;
}

double IBS(double lo = 0.0, double hi = 10000.0, double mid = 0.0, double ans =
		0.0) {
	for (int i = 0; i < 50; i++) {
		mid = (lo + hi) / 2.0;
		if (can(mid)) {
			ans = mid, hi = mid;
		} else
			lo = mid;
	}
	return ans;
}
double BS(double lo = 0.0, double hi = 10000.0, double mid = 0.0, double ans =
		0.0) {
	while (fabs(hi - lo) > EPS) {
		mid = (lo + hi) / 2.0;
		if (can(mid)) {
			ans = mid;
			hi = mid;
		} else
			lo = mid;
	}
	return ans;
}
int main() {
	file(); // TODO
	string s;
	while (in(d) and cin >> s >> s and in(n)) {
		if (!d and !n)
			break;
		mem(J,0), J[0][0] = n, g = 0;
		while (1) {
			in(d) and cin >> s, g++, J[g][4] = d;
			if (s == "Goal") {
				if (!d)
					otf(0.000), ln();
				else
					otf(IBS()), ln();
				break;
			} else if (s[0] == 'F')
				cin >> s, in(n), J[g][0] = n;
			else if (s[0] == 'L')
				J[g][1]++;
			else if (s[0] == 'G')
				cin >> s, J[g][2] = 1;
			else if (s[0] == 'M')
				J[g][3] = 1;
		}
	}

	return 0;
}
