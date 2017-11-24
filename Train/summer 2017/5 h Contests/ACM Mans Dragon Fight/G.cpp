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

const lli N = 1e3 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int p, q, r, s, t, u;

double fun(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
	file();
	int T;
	cin >> T;
	while (T--) {
		cin >> p >> q >> r >> s >> t >> u;
		double lo, hi, mi, f;

		if (fun(1) > 1e-9 || p + r + u < 0)
			printf("No solution\n");
		else {

			lo = 0.0;
			hi = 1.0;

			for (int i = 0; i < 30; i++) {
				mi = (lo + hi) / 2;

				f = fun(mi);

				if (f > 0)
					lo = mi;
				else
					hi = mi;
			}
			printf("%.4f\n", lo);
		}
	}
	return 0;
}


/*
 *
 *
//	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
 */
