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

lli n, k;

void solve(lli n, lli idx, lli cnt = 0) {
	if (n == 1) {
		cout << n;
		return;
	}
	if (!cnt) {
		idx = (idx / 2) + 1;
		if (idx == k) {
			cout << n;
			return;
		}
		n--, cnt++;
	} else {
		lli ind = ((idx - 1) / 2) + 1;
		if (k % idx == ind) {
			cout << n;
			return;
		}
		n--, idx = ind, cnt++;
	}

	solve(n, idx, cnt);
}

int main() {
	freopen("in.txt", "r", stdin);
//	int T;
//	cin >> T;
//	while (T--){
//
//	}
	cin >> n >> k;
	solve(n, pow(2, n) - 1);
	return 0;
}
