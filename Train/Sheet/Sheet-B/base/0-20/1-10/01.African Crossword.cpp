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

int v[101][101], n, m;
char arr[101][101];

void check(int ii, int jj) {
	bool ok = 1;
	if (v[ii][jj])
		return;
	v[ii][jj] = 1;
	for (int i = 0; i < n; ++i) {
		if (i == ii || v[i][jj])
			continue;
		if (arr[i][jj] == arr[ii][jj]) {
			check(i, jj);
			arr[i][jj] = '.';
			ok = 0;
		}
	}
	for (int j = 0; j < m; ++j) {
		if (j == jj || v[ii][j])
			continue;
		if (arr[ii][j] == arr[ii][jj]) {
			check(ii, j);
			arr[ii][j] = '.';
			ok = 0;
		}
	}
	if (!ok)
		arr[ii][jj] = '.';
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (arr[i][j] != '.')
				check(i, j);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (arr[i][j] != '.')
				cout << arr[i][j];
	return 0;
}
