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
	freopen("boring.in", "r", stdin);
#endif
}
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
	file();
	int T;
	cin >> T;
	while (T--) {
		bool ar[1000009] = { 0 }, ar2[100009] = { 0 };
		int n, x, y, i;
		cin >> n >> x >> y;
		for (i = x;; i += x) {
			if (i > n)
				break;
			ar[i] = 1;
		}

		for (i = y;; i += y) {
			if (i > n)
				break;
			ar2[i] = 1;
		}

		int ret = 0;
		for (i = 1; i <= n; i++) {
			if (ar[i]) {
				if (ar2[i + 1])
					ret++;
				if (ar2[i - 1])
					ret++;
				if (ar2[i])
					ret++;

			}
		}
		cout << ret << endl;
	}
	return 0;
}
