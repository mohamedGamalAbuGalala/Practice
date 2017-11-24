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
		int n, cnt = 0, ar[18] = { 0 };
		cin >> n;
		if (n == 1) {
			cin >> ar[cnt] >> ar[cnt];
			cout << "weak\n";
			continue;
		}
		for (int i = 0; i < n; ++i) {
			cin >> ar[cnt++];
			cin >> ar[cnt++];
		}
		cnt = 0;
		bool con = 1;
		for (int i = 0; i < n -1 && con; ++i, cnt += 2)
			if (ar[cnt] != ar[cnt + 2] && ar[cnt + 1] != ar[cnt + 3]) {
				cout << "strong\n";
				con = 0;
			}
		if (!con)
			continue;
		cout << "weak\n";
	}
	return 0;
}
