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

const lli maxN = 10e6 * 4;
const lli maxE = 1e5 + 10;

int ar[10];

bool mark(int n) {
	while (n) {
		int d = n % 10;
		n /= 10;
		ar[d]++;
	}
	for (int i = 0; i < 10; ++i) {
		if (ar[i] == 0)
			return 0;
	}
	return 1;
}

int main() {
	freopen("in.txt", "r", stdin);
//	freopen("input_file.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, n, tt = 1;
	scanf("%d\n", &T);
	while (T--) {
		memset(ar, 0, sizeof ar);
		scanf("%d\n", &n);
		if (!n) {
			cout << "Case #" << tt++ << ": " << "INSOMNIA" << endl;
			continue;
		}
		int cnt = 1, nn = n;
		while (n < maxN) {
			if (mark(n)) {
				cout << "Case #" << tt++ << ": " << n << endl;
				break;
			}
			n = nn * ++cnt;
		}
		if (n >= maxN)
			cout << "Case #" << tt++ << ": " << "INSOMNIA" << endl;
	}
	return 0;
}

