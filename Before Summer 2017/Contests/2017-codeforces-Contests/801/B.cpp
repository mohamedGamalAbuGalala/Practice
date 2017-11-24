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
	string x, y, z;
	cin >> x >> z;
	for (int i = 0; i < (int) z.size(); ++i)
		y += '.';
	for (int i = 0; i < (int) z.size(); ++i) {
		if (x[i] == z[i])
			y[i] = 'z';
		else if (x[i] != z[i] && z[i] <= x[i])
			y[i] = z[i];
	}
	for (int i = 0; i < (int) y.size(); ++i) {
		if (y[i] == '.') {
			cout << -1;
			return 0;
		}
	}
	cout << y;
	return 0;
}
