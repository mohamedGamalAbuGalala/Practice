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
	int n, ar[51][51] = { 0 };
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n && cin >> ar[i][j]; ++j)
			;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ar[i][j] == 1)
				continue;
			bool good = 0;
			for (int k = 0; k < n; ++k) {
				for (int l = 0; l < n; ++l) {
					if (ar[i][j] == (ar[i][k] + ar[l][j]))
						good = 1;
				}
			}
			if (!good)
				return cout << "no", 0;
		}
	}
	cout << "yes";
	return 0;
}
