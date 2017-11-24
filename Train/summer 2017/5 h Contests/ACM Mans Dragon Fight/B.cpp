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

const lli N = 1e5 + 3;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int main() {
	file();
	string val;
	lli a, b;
	cin >> val >> a >> b;
	int n = val.size();
	int dpa[n] { } , dpb[n] { };


	lli pw = 10 % b;

	dpa[0] = (val[0] - '0') % a;
	dpb[n - 1] = (val[n - 1] - '0') % b;

	for (int i = 1; i < n; i++) {

		dpa[i] = (dpa[i - 1] * 10 + val[i] - '0') % a;

		int bidx = n - i;
		dpb[bidx - 1] = (dpb[bidx] + (val[bidx - 1] - '0') * pw) % b;
		pw = pw * 10 % b;

	}
	int idx = 0;
	while (idx < n - 1
			&& (dpa[idx] != 0 || dpb[idx + 1] != 0 || val[idx + 1] == '0'))
		idx++;

	if (idx == n - 1)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i <= idx; i++)
			cout << val[i];
		cout << '\n';
		for (int i = idx + 1; i < n; i++)
			cout << val[i];
		cout << '\n';
	}
	return 0;
}
