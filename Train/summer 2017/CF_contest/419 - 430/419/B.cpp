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

const lli N = 2e5 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int main() {
	file();
	int n, k, q, a, b, ar[N] { 0 }, cur = -1, res;
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a, &b);
		ar[a]++, ar[b + 1]--;
	}
	for (int i = 1; i <= N; ++i)
		ar[i] += ar[i - 1];
	for (int i = 1; i <= N; ++i) {
		if (ar[i] >= k)
			++cur;
		ar[i] = cur;
	}
	ar[0] = -1;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &a, &b);
		if (ar[a - 1] == ar[b])
			res = 0;
		else
			res = ar[b] - ar[a - 1];
		printf("%d\n", res);
	}
	return 0;
}
