#include <bits/stdc++.h>

#define INF 1e18
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 10000;
const lli maxE = 1e5 + 10;

int main() {
	freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	int res = 0, v[101] = { 0 };
	for (int i = 0; i < (int) s.size() - 1; ++i) {
		char cur = s[i], nxt = s[i + 1];
		if (cur == 'V' && nxt == 'K')
			res++, v[i] = 1, v[i + 1] = 1, i++;
	}
	for (int i = 0; i < (int) s.size(); ++i) {
		char cur = s[i], nxt = s[i + 1];
		if (!v[i] && !v[i + 1]) {
			if (cur == 'V' && nxt == 'V') {
				res++;
				break;
			} else if (cur == 'K' && nxt == 'K') {
				res++;
				break;
			}
		}
	}
	cout << res;
	return 0;
}
