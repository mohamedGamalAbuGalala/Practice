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

int main() {
	file();
	int cnt2 = 0, cnt = 2, ans;
	lli s;
	double res = N, ang, a, n;
	cin >> n >> a;
	int mxAng = n - 2;
	s = mxAng * 180;
	ang = s / n, mxAng--;
	if (abs(ang - a) < res)
		res = abs(ang - a), ans = 3;
	if (!mxAng)
		return cout << "1 2 " + to_string((int) n), 0;
	ang /= n - 2.0, mxAng--;
	if (abs(ang - a) < res)
		res = abs(ang - a), ans = (int) n;
	while (mxAng-- && ++cnt2) {
		double ng = ang * cnt++, tmp = abs(ng - a);
		if (tmp < res)
			res = tmp, ans = n - cnt2;
	}
	cout << "1 2 " << ans;
	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
