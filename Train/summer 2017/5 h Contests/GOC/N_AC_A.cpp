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
const int MN = 1e5 + 1e2;
const int MW = 1e3 + 5;
typedef long long int lli;
const int OO = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
	file(); // TODO
	bool flag = false;

	map<int, vector<int>> mv;
	int n, m, a, b, pre, last, ans = 0, frst;
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mv[x].push_back(i);
	}

	if (a > b) {
		map<int, vector<int>>::iterator it = mv.end();

			if (find(all(it->second), a) != it->second.end()) {
				flag = true;
			}
			if (find(all(it->second), b) != it->second.end()) {
				cout << ans;
				return 0;
			} else {
				pre = it->first;
				frst = it->second[0];
				last = it->second[sz(it->second) - 1];
				it--;

			}

			while (it != mv.begin()) {
				if (find(all(it->second), a) != it->second.end()) {
					flag = true;
				}
				if (flag) {
					if ((it->first - pre) > 1) {
						cout << -1;
						return 0;
					}

					int small = 999999999;
					for (int i = 0; i < sz(it->second); i++) {
						small = min(small, abs(frst - it->second[i]));
					}
					for (int i = 0; i < sz(it->second); i++) {
						small = min(small, abs(last - it->second[i]));
					}
					ans += small;
					pre = it->first;
					frst = it->second[0];
					last = it->second[sz(it->second) - 1];
					if (find(all(it->second), b) != it->second.end()) {
						break;
					}

				}

				it--;
			}

	}
	else{

		map<int, vector<int>>::iterator it = mv.begin();

		if (find(all(it->second), a) != it->second.end()) {
			flag = true;
		}
		if (find(all(it->second), b) != it->second.end()) {
			cout << ans;
			return 0;
		} else {
			pre = it->first;
			frst = it->second[0];
			last = it->second[sz(it->second) - 1];
			it++;

		}

		while (it != mv.end()) {
			if (find(all(it->second), a) != it->second.end()) {
				flag = true;
			}
			if (flag) {
				if ((it->first - pre) > 1) {
					cout << -1;
					return 0;
				}

				int small = 999999999;
				for (int i = 0; i < sz(it->second); i++) {
					small = min(small, abs(frst - it->second[i]));
				}
				for (int i = 0; i < sz(it->second); i++) {
					small = min(small, abs(last - it->second[i]));
				}
				ans += small;
				pre = it->first;
				frst = it->second[0];
				last = it->second[sz(it->second) - 1];
				if (find(all(it->second), b) != it->second.end()) {
					break;
				}

			}

			it++;
		}
	}

	cout << ans;
	return 0;
}
