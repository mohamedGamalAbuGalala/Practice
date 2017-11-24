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

const lli N = 1e6 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int r = 0, rr = 0, c, v, vm, a, l, cnt = 1;

int main() {
	file();
	scanf("%d%d%d%d%d", &c, &v, &vm, &a, &l);
	rr = r = v;
	while (rr < c) {
		r = v + (a * cnt);
		if (r > vm)
			r = vm;
		cnt++, rr += r - l;
	}
	cout << cnt;
	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
