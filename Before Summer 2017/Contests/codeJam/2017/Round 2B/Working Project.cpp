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
	freopen("out.txt", "w", stdout);
	string cr = { 'R', 'O', 'Y', 'G', 'B', 'V' };
	int t, tt = 0, n;
	cin >> t;
	while (t--) {
		cin >> n;
		string res;
		for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			while (tmp--)
				res.pb(cr[i]);
		}
		cout << "Case #" << ++tt << ": ";
	}
	return 0;
}
