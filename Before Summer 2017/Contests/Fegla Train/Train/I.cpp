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

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int n, k, res = 0, ch[26] = { 0 };
		string inp;
		cin >> n >> k;
		for (int i = 0; i < 26 && cin >> ch[i]; ++i)
			;
		for (int i = 0; i < n; ++i) {
			cin >> inp;
			res = 0;
			for (int j = 0; j < (int) inp.size(); ++j)
				res += ch[inp[j] - 'a'];
			if (res >= k)
				cout << inp << "\n";
		}
	}
	return 0;
}
