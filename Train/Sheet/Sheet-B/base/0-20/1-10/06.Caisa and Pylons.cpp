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

const lli N = 2e8 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int main() {
	file();
	lli res = 0;
	int n, ar[(int) 1e5 + 5];
	cin >> n;
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	res+= ar[0];
	lli pwr = 0;
	for (int i = 0; i < n - 1; ++i) {
		int cur  = ar[i] , nxt = ar[i+1];
		if ( cur == nxt)
			continue;
		lli l = nxt - cur - pwr;
		if(l > 0)
			res += l , pwr = 0;
		else if ( nxt < cur)
			pwr += cur - nxt;
		else
			pwr -= nxt - cur;
	}
	return cout << res, 0;
}
