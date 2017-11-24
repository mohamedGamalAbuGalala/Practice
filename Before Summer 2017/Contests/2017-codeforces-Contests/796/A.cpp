#include <bits/stdc++.h>

#define INF 1e6
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

const lli maxN = 10e6 * 4;
const lli maxE = 1e5 + 10;

int main() {
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n, m, k, ar[102];
	cin >> n >> m >> k;
	m--;
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	int l = m - 1, r = m + 1;
	while (r < n || l > -1) {
		if (r < n && ar[r] <= k && ar[r] != 0) {
			cout << (r - m) * 10;
			return 0;
		}
		if (l > -1 && ar[l] <= k && ar[l] != 0) {
			cout << (m - l) * 10;
			return 0;
		}
		l--, r++;
	}
	return 0;
}

