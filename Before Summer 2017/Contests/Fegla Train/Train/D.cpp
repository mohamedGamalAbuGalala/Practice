//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
// Description : Hello World in C++, Ansi-style
//============================================================================

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
typedef vector<vector<ii> > vvii;

const lli N = 1e2;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int n;
		int ar[9][9] = { 0 };
		vi a;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			a.pb(i);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> ar[i][j];
		int mn = 1e3;
		do {
			int res = 0;
			for (int i = a.size() - 1; i > 0; --i) {
				int cur = a[i], nxt = a[i - 1];
				if (!ar[cur][nxt])
					res++;
			}
			mn = min(res, mn);
		} while (next_permutation(a.begin(), a.end()));
		cout << mn << "\n";
	}
	return 0;
}
