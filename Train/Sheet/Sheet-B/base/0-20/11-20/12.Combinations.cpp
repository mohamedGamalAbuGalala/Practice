//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include <string>

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

const lli N = 1e5 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

lli perm(int n, vi s) {
	vi num, den;
	lli ret = 1;

	sort(s.begin(), s.end());

	for (int i = s[(int) s.size() - 1] + 1; i <= n; ++i)
		num.pb(i);

	for (int i = 0; i < (lli) s.size() - 1; ++i) {
		int nn = s[i];
		for (int j = 1; j <= nn; ++j)
			den.pb(j);
	}

	int numId = num.size() - 1;
	for (int i = 0; i < (lli) den.size(); ++i) {
		int cur = den[i];
		int cntInf = 0;
		while (cur > 1 && (cntInf < (int) num.size())) {
			if (numId < 0)
				numId = num.size() - 1;
			if (num[numId] <= 1)
				numId--;
			if (numId < 0)
				numId = num.size() - 1;
			int gcd = __gcd(num[numId], cur);
			if (gcd == 1)		// what to do here
				numId--;
			else
				num[numId] /= gcd, cur /= gcd;
			cntInf++;
		}
		den[i] = cur;
	}

	lli dret = 1;
	for (int i = 0; i < (int) den.size(); ++i)
		dret *= den[i];

	for (int i = 0; i < (lli) num.size(); ++i)
		ret *= num[i];
	ret /= dret;

	return ret;
}

int main() {
	file();
	int n, m;
	while (cin >> n >> m && (n || m))
		cout << n << " things taken " << m << " at a time is "
				<< perm(n, { m, n - m }) << " exactly.\n";

	return 0;
}
