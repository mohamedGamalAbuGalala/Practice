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
	//freopen("*.in", "r", stdin);
#endif
}
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
	file();
//	int T;
//	cin >> T;
//	while (T--){
//
//	}
	int a = 0, i = 0, j, ans;
	string inp;
	cin >> j >> inp;
	for (j = 0; j < (int) inp.size(); ++j) {
		char cur = inp[j];
		if (cur == 'A')
			a++;
		else if (cur == 'I')
			i++;
	}
	if (i == 0)
		ans = a;
	else if (i == 1)
		ans = 1;
	else
		ans = 0;
	cout << ans;
	return 0;
}
