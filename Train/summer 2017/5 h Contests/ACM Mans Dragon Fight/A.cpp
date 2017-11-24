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

const lli N = 1e5 + 3;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int main() {
	file();
	int n, ar[N];
	cin >> n;
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	int l = 0, r = n - 1, b1 = 0, b2 = 0;
	while (l < r) {
		int mn = min(ar[l], ar[r]);
		ar[l] -= mn, ar[r] -= mn;
		if (l == r - 1 && ar[l])
			b1++, l++;
		else if (!ar[l])
			b1++, l++;
		if (r == l && ar[r])
			b2++, r--;
		else if (!ar[r])
			b2++, r--;
	}
	if (l == r)
		b1++;
	cout << b1 << " " << b2 << "\n";
	return 0;
}
