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
#define otf(x) printf("%.2lf", x)
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

double beauty[] { 12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44,
		0.00, 4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90,
		0.02, 0.22, 0.90, 0.52 };
//, avg[8][26], sm[8][26], cnt[8][26];
//int cvs[26], csz;
char s[10];
//map<char, bool> vo;
//
double bue(char c[], int cs) {
	double res = 0;
	for (int i = 1; i <= cs; ++i)
		res += (i * beauty[c[i - 1] - 'a']);
	return res;
}
//
//void bT(int i) {
//	if (i - 1 == csz) {
//		double bb = bue(s, csz);
//		sm[csz][s[0] - 'a'] += bb, cnt[csz][s[0] - 'a']++;
//		return;
//	}
//	for (int j = 0; j < 26; ++j)
//		if (cvs[j] < 2) {
//			if (i & 1) {
//				if (!vo[j + 'a'])
//					cvs[j]++, s[i - 1] = (j + 'a'), bT(i + 1), cvs[j]--;
//			} else {
//				if (vo[j + 'a'])
//					cvs[j]++, s[i - 1] = (j + 'a'), bT(i + 1), cvs[j]--;
//			}
//		}
//}

double avg[8][26] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1.42, 4.68, 5.86, 0, 0.69, 1.01, 0.7, 0, 0.44, 0,
		4.97, 3.15, 6.71, 0, 2.51, 0.88, 6.87, 7.98, 4.63, 0, 0.9, 0.02, 0.22,
		0.9, 0.52, 0, 19.448, 22.708, 23.888, 0, 18.718, 19.038, 18.728, 0,
		18.468, 18.028, 22.998, 21.178, 24.738, 0, 20.538, 18.908, 24.898,
		26.008, 22.658, 0, 18.928, 18.048, 18.248, 18.928, 18.548, 0, 27.3137,
		30.5737, 31.7537, 0, 26.5837, 26.9037, 26.5937, 0, 26.3337, 25.8937,
		30.8637, 29.0437, 32.6037, 0, 28.4037, 26.7737, 32.7637, 33.8737,
		30.5237, 0, 26.7937, 25.9137, 26.1137, 26.7937, 26.4137, 0, 63.3697,
		66.6297, 67.8097, 0, 62.6397, 62.9597, 62.6497, 0, 62.3897, 61.9497,
		66.9197, 65.0997, 68.6597, 0, 64.4597, 62.8297, 68.8197, 69.9297,
		66.5797, 0, 62.8497, 61.9697, 62.1697, 62.8497, 62.4697, 0, 76.5011,
		79.7018, 80.8604, 0, 75.7844, 76.0985, 75.7942, 0, 75.5389, 75.1069,
		79.9865, 78.1996, 81.6949, 0, 77.5713, 75.9709, 81.852, 82.9418,
		79.6527, 0, 75.9905, 75.1265, 75.3229, 75.9905, 75.6175, 0, 130.585,
		133.786, 134.944, 0, 129.868, 130.183, 129.878, 0, 129.623, 129.191,
		134.071, 132.284, 135.779, 0, 131.655, 130.055, 135.936, 137.026,
		133.737, 0, 130.075, 129.211, 129.407, 130.075, 129.701, 0, 148.993,
		152.045, 153.15, 0, 148.31, 148.609, 148.319, 0, 148.076, 147.664,
		152.317, 150.613, 153.946, 0, 150.014, 148.488, 154.096, 155.135,
		151.999, 0, 148.506, 147.682, 147.87, 148.506, 148.151 };

int main() {
	file(); //TODO
//	vo['a'] = 1, vo['e'] = 1, vo['i'] = 1, vo['o'] = 1, vo['u'] = 1;
//	csz = 1, bT(1), csz = 2, bT(1), csz = 3, bT(1), csz = 4, bT(1);
//	csz = 5, bT(1);
//	csz = 6, bT(1);
//	csz = 7, bT(1);
//	for (int j = 0; j < 26; ++j)
//		ots("0,");
//	for (int i = 1; i <= 7; ++i)
//		for (int j = 0; j < 26; ++j)
//			avg[i][j] = (!cnt[i][j]) ? 0 : (sm[i][j] / cnt[i][j]), cout
//					<< (avg[i][j]), otc(',');
	int n;
	in(n);
	string inp;
	while (n-- and cin >> inp) {
		for (int i = 0; i < sz(inp); ++i)
			s[i] = inp[i];
		double bb = bue(s, sz(inp));
		if (bb < avg[sz(inp)][inp[0] - 'a'])
			puts("below");
		else
			puts("above or equal");
	}
	return 0;
}
