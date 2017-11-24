#include <bits/stdc++.h>

#define INF 1e6
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 10e6 * 4;
const lli maxE = 1e5 + 10;

/*
 *
 *those S for which min(LS, RS) is maximal.
 *			those If there is only one such stall,
 *					they choose it;
 *			otherwise,
 *					they choose
 the one among those where
 max(LS, RS) is maximal.

 If there are still multiple tied stalls,
 they choose the leftmost stall among those.
 *
 *	4	2
 *	O	. 	.	.	.	O
 *	O	.	O	.	.	O
 *	O	.	O	O	.	O
 *
 *	5	2
 *	O	.	.	o	.	.	O
 *	O	o	.	o	.	.	O
 *
 *	6	2
 *	O	.	.	o	.	.	.	O
 *	O	.	.	o	.	o	.	O
 *
 */

//lli solve(lli n, lli k, int level, lli l) {
//	if (k <= 0)
//		return l;
//	return solve(n / 2, k - pow(2, level), level + 1, n);
//}
lli solve(lli n, lli k) {
	if ((k - (k / 2)) < 0 || k == 1) {
		return n;
	}
	int nn = (n & 1) ? (n / 2) : (n - (n / 2)), kk =
			!(k & 1) ? (k / 2) : (k - (k / 2));
	return solve(nn, kk);
}

/*		000011
 * 		000001
 * 		000001
 *
 *	13	6
 *	O	.	.	.	.	.	.	O	.	.	.	.	.	.	O
 6	5
 *	O	.	.	O	.	.	.	O	.	.	O	.	.	.	O
 3	3
 *	O	o	.	O	.	O	.	O	.	.	O	.	O	.	O


 *	O	.	.	o	.	.	.	O
 *	O	.	.	o	.	o	.	O
 *	O	o	.	o	.	o	.	O
 *	O	o	.	o	.	o	o	O
 *	O	o	o	o	.	o	o	O



 *	O	.	.	.	O	.	.	.	O
 *	O	.	O	.	O	.	O	.	O
 *	O	.	O	.	O	.	O	.	O
 *
 *
 *	O	.	.	O
 *
 *
 */

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	lli n;
	lli k;
	int t, tt = 1;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n == k) {
			cout << "Case #" << tt++ << ": " << 0 << " " << 0 << endl;
			continue;
		}
		lli ret = solve(n, k);
		if (!ret)
			cout << "Case #" << tt++ << ": " << 0 << " " << 0 << endl;
		else if (ret == 2 || ret == 1)
			cout << "Case #" << tt++ << ": " << 1 << " " << 0 << endl;
		else if (ret & 1)
			cout << "Case #" << tt++ << ": " << ret / 2 << " " << ret / 2
					<< endl;
		else
			cout << "Case #" << tt++ << ": " << (ret / 2) << " "
					<< (ret / 2) - 1 << endl;
	}
	return 0;
}

