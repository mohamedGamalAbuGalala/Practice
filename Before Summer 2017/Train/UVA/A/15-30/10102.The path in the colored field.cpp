#include <bits/stdc++.h>

#define INF 1e6
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 20000 + 10;
const lli maxE = 1e5 + 10;

char ar[102][102];

int n;

int sol(int x, int y) {
	int ret = INF;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (ar[i][j] == '3')
				ret = min(ret, abs(x - i) + abs(y - j));
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			cin >> ar[i];
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (ar[i][j] == '1')
					res = max(res, sol(i, j));
		cout << res << "\n";
	}
}

