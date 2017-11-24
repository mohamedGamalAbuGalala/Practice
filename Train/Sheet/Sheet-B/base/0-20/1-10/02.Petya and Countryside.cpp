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
	int n, ar[1001];
	cin >> n;
	for (int i = 0; i < n && cin >> ar[i]; ++i)
		;
	int mx = -1;
	for (int i = 0; i < n; ++i) {
		int cur = ar[i], nxt = i + 1, lst = i - 1, res = 1;
		while (nxt < n && ar[nxt] <= cur)
			res++, cur = ar[nxt++];
		cur = ar[i];
		while (lst >= 0 && ar[lst] <= cur)
			res++, cur = ar[lst--];
		mx = max(mx, res);
	}
	cout << mx;
	return 0;
}
