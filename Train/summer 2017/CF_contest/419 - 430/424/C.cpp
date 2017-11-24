#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ots(x) printf("%s ", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define ssz(ss) ((int)strlen(s))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
// constants
const int MN = 1e6 + 1e5;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<lli, string> lls;

int s[2050], a[2050];

int main() {
	file();
	int n, k, cnt = 0, ok = 0;
	set<int> dif;
	vector<int> x;
	cin >> k >> n;
	for (int i = 1; i <= k; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
		dif.insert(s[i]);
	}

	for (auto it : dif)
		x.push_back(it);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	for (int i = 0; i <= sz(x)- n; i++) {
		ok = 1;
		for (int j = 1; j < n; j++) {
			auto it = lower_bound(x.begin(), x.end(), x[i] + a[j] - a[0]);
			if ((x.end() - it) < n - j || *it != x[i] + a[j] - a[0]) {
				ok = 0;
				break;
			}
		}
		if (ok)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
