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
	int hh, mm, res = 0;
	string t;
	cin >> t;
	string h = t.substr(0, 2), m = t.substr(3, 4);
	istringstream bufhh(h);
	bufhh >> hh;
	istringstream bufmm(m);
	bufmm >> mm;

	while (1) {
		string mn = to_string(mm), ho = to_string(hh);
		if (mm < 10)
			mn = "0" + mn;
		if (hh < 10)
			ho = "0" + ho;
		if (ho[0] == mn[1] && ho[1] == mn[0])
			break;
		if (mm < 59)
			mm++, res++;
		else if (hh < 23)
			hh++, mm = 0, res++;
		else
			hh = 0, mm = 0, res++;
	}
	cout << res;
	return 0;
}
