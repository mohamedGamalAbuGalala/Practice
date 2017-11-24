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

int main() {
	file();
	int n, m, k, res = 0;
	lli x[10002];
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m + 1; ++i)
		scanf("%lld", &x[i]);
	string mm = bitset<20>(x[m]).to_string();
	for (int i = 0; i < m; ++i) {
		string tmp = bitset<20>(x[i]).to_string();
		int dif = 0;
		for (int j = 0; j < 20; ++j)
			if (tmp[j] != mm[j])
				dif++;
		if (dif <= k)
			res++;
	}
	cout << res;
	return 0;
}
