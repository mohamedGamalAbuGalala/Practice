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
	int n;
	while (cin >> n && n > 0) {

		int inp[51] { 0 }, nn = 0, sm = 0;
		for (int i = 0; i < n && cin >> inp[i]; ++i)
			;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (__gcd(inp[i], inp[j]) == 1)
					nn++;
		if (!nn || n == 1) {
			cout << "No estimate for this data set.\n";
			continue;
		}
		sm = n * (n - 1) / 2;
		double pi = sqrt((double) 6 * sm / nn);
		printf("%.6lf\n", pi);
	}
	return 0;
}
