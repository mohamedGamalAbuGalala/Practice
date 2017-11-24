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

const lli N = 1e3 + 4;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int ar[2][3][N], n,idx;

void solve() {
	int d1 = -1, d2 = -1, ms = -1;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (ar[idx][0][i] == ar[idx][0][j]) {
				d1 = i, d2 = j;
				break;
			}
	for (ms = 1; ms <= n; ++ms) {
		bool f = 0;
		for (int i = 0; i < n; ++i)
			if (ar[idx][0][i] == ms) {
				f = 1;
				break;
			}
		if (!f)
			break;
	}
	memcpy(ar[idx][1], ar[idx][0], n * sizeof(int));
	memcpy(ar[idx][2], ar[idx][0], n * sizeof(int));
	ar[idx][1][d1] = ms;
	ar[idx][2][d2] = ms;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n && cin >> ar[0][0][i]; ++i)
		;
	for (int i = 0; i < n && cin >> ar[1][0][i]; ++i)
		;

	idx = 0;
	solve();
	idx = 1;
	solve();

	int res;
	if (!memcmp(ar[0][1], ar[1][1], n * sizeof(int)) || !memcmp(ar[0][1], ar[1][2], n * sizeof(int)))
		res = 1;
	else
		res = 2;
	for (int i = 0; i < n; ++i)
		printf("%d%c", ar[0][res][i], i == n - 1 ? '\n' : ' ');
	return 0;
}
