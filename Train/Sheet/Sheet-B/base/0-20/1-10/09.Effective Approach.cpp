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

int main() {
	file();
	lli r1 = 0, r2 = 0;
	int i, ar[N] = { 0 }, q[N] = { 0 }, v[N] = { 0 }, n, qq;
	cin >> n;
	for (i = 0; i < n && cin >> ar[i]; ++i)
		;
	cin >> qq;
	for (i = 0; i < qq && cin >> q[i]; ++i)
		;
	for (i = 0; i < n; ++i)
		v[ar[i]] = i;
	for (int k = 0; k < qq; ++k) {
		int cur = q[k];
		i = v[cur];
		r1 += i + 1, r2 += n - i;
	}
	cout << r1 << " " << r2;
	return 0;
}
