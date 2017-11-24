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
	int n, a, ar[101], res = 0;
	cin >> n >> a;
	a--;
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	int l = a - 1, r = a + 1;
	if (ar[a])
		res++;
	while (l > -1 || r < n) {
		if (ar[l] && r >= n)
			res++;
		else if (ar[r] && l < 0)
			res++;
		else if (ar[l] && ar[r])
			res += 2;
		l--, r++;
	}
	return cout << res, 0;
}
