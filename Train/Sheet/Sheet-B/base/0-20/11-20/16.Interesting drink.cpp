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

const lli N = 1e6 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int main() {
	file();
	int n, x, q, com[N] { 0 }, qq, mx = -1;
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d", &x); ++com[x], ++i)
		mx = max(mx, x);
	for (int i = 1; i <= mx; ++i)
		com[i] += com[i - 1];
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d", &qq);
		if (qq > mx)
			qq = mx;
		printf("%d\n", com[qq]);
	}
	return 0;
}
