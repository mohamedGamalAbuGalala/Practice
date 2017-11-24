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

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 2e4 + 3;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int main() {
	file();
	for (int i = 1; i < 75; ++i) {
		cout<<i<<"\n";
	}
	return 0;
	int n = 74, q = 31;
	string ar[n][q];
	vi expt = { 3, 7, 14, 16, 17, 27, 28 };
	vi resul;
	string s;
	for (int i = 0; i < (int) expt.size(); ++i)
		expt[i]--;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < q; ++j) {
			cin >> ar[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		int res = 0;
		for (int j = 0; j < q; ++j) {
			bool ex = 0;
			for (int k = 0; k < (int) expt.size(); ++k)
				if (expt[k] == j) {
					ex = 1;
					break;
				}

			if (!ex) {
				if (ar[i][j] == "نعم")
					res += 2;
				else if (ar[i][j] == "لا")
					res += 1;
			} else {
				if (ar[i][j] == "نعم")
					res += 1;
				else if (ar[i][j] == "لا")
					res += 2;
			}
		}
		resul.pb(res);
	}

	double overal = 0;
	for (int i = 0; i < (int) resul.size(); ++i) {
		double ans = ((double) resul[i] / 64) * 100;
		overal += ans;
		cout << setprecision(4) << ans << "%\n";
	}
	cout << "overal percent\n" << overal / (int) resul.size() << "%\n";

	return 0;
}
