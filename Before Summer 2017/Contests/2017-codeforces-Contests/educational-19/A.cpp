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

ii sol(int x) {
	for (int i = sqrt(x); i > 0; i--) {
		// integer division discarding remainder:
		int j = x / i;
		if (j * i == x) {
			// closest pair is (i,j)
			return ii(i, j);
		}
	}
	return ii(-1, -1);
}

int main() {
	freopen("in.txt", "r", stdin);
	int data[21] = { }, ans = 0, n, k;
	cin >> n >> k;
	for (int i = 2; k > 1 && n > 1; i++)
		for (; k > 1 && n % i == 0; k--, n /= i)
			data[++ans] = i;
	if (n == 1) {
		cout << -1;
	} else {
		for (int i = 1; i <= ans; i++)
			cout << data[i] << ' ';
		cout << n;
	}
	return 0;
}

