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

void calc(lli &a, lli &res) {
	while (a > 1) {
		if (a & 1)
			a = (a / 2) + 1;
		else
			a /= 2;
		res++;
	}
}

int main() {
	freopen("unit.in", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		lli a, b, c;
		cin >> a >> b >> c;
		lli res = 0;
		calc(a, res);
		calc(b, res);
		calc(c, res);
		cout << res << "\n";
	}
	return 0;
}
