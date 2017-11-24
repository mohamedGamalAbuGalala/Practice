#include <bits/stdc++.h>

#define INF 1000000000
#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 20000 + 10;
const lli maxE = 1e5 + 10;

int main() {
	freopen("in.txt", "r", stdin);
	int a, b, c, d, fp = -1, sp = -1;
	cin >> a >> b >> c >> d;
	if ((a % 2 == 0) && (b % 2 == 1))
		fp = 1;		// fp is always odd
	if ((c % 2 == 0) && (d % 2 == 1))
		sp = 1;		// sp is always odd
	if ((c % 2 == 0) && (d % 2 == 0))
		sp = 0;		// sp is always even
	if ((a % 2 == 0) && (b % 2 == 0))
		fp = 0;		// fp is always even
	if (b == d) {
		cout << b << "\n";
		return 0;
	} else if ((fp == 1 && sp == 0) || (fp == 0 && sp == 1)) {
		cout << "-1\n";
		return 0;
	} else {
		int bb = b, dd = d, cntb = 1, cntd = 1;
		while (bb != dd && cntb < 1000 && cntd < 1000) {
			if (bb < dd)
				bb = b + (a * cntb++);
			else if (bb > dd)
				dd = d + (c * cntd++);
		}
		if (cntb == 1000 || cntd == 1000) {
			cout << "-1\n";
			return 0;
		}
		cout << bb << "\n";
	}
}
