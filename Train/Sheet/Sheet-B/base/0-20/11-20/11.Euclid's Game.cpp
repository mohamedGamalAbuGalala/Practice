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

int x = 0;

int fun(long long a, long long b) {
	if (b == 0)
		return 0;
	int ret = 0;
	if (a / b > 1)
		ret = ret | !fun(b + a % b, b);
	ret = ret | !fun(b, a % b);
	//ret = ret ^ 1;
	return ret;
}

void func(lli a, lli b) {
	if (b == 0) {
		string xx = (x & 1) ? "Stan" : "Ollie";
		cout << xx << " wins\n";
		return;
	}
	a = max(a, b), b = min(a, b);
	x++;
	if (a / b > 1)
		func(b + a % b, b);
	else
		func(b, a % b);
}

void slv(lli n, lli m) {
	if (m == 0) {
		string xx = (x & 1) ? "Stan" : "Ollie";
		cout << xx << " wins\n";
		return;
	}
	n %= m, x++;
	slv(max(m, n), min(m, n));
}

int main() {
	file();
	lli n, m;
	string res[] { "Stan wins\n", "Ollie wins\n" };
	while (cin >> n >> m && (n || m)) {
		x = 0;
//		slv(max(m, n), min(m, n));
		cout << res[!fun(max(m, n), min(m, n))];
		func(max(m, n), min(m, n));
	}
	return 0;
}
