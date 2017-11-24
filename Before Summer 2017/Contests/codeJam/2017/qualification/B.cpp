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

lli n;

bool ideal(vector<lli> ar) {
	lli m = ar[0];
	for (int i = 0; i < (int) ar.size(); ++i) {
		m = max(m, ar[i]);
		if (ar[i] < m)
			return 0;
	}
	return 1;
}

lli sol(lli n) {
	lli nn = 0;
	vector<lli> ar;
	while (n) {
		int d = n % 10;
		ar.pb(d);
		n /= 10;
	}

	reverse(ar.begin(), ar.end());

	while (!ideal(ar)) {
		for (int i = (int) ar.size() - 1; i >= 0; --i)
			for (int j = i - 1; j >= 0; --j)
				if (ar[i] < ar[j]) {
					ar[j]--;
					for (int k = j + 1; k < (int) ar.size(); ++k)
						ar[k] = 9;
				}
	}

	for (int i = 0; i < (int) ar.size(); ++i) {
		nn *= 10;
		nn += ar[i];
	}
	return nn;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, tt = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		cout << "Case #" << tt++ << ": " << sol(n) << endl;
	}
	return 0;
}

