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

int v[1000000];
int main() {
	freopen("in.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int tmp;
		scanf("%d ", &tmp);
		v[tmp] = 1;
	}
	int cur = 1;
	if (v[1]) {
		cout << 1;
		return 0;
	}
	scanf("\n");
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d %d\n", &a, &b);
		if ((a == cur || b == cur) && (v[b] == 1 || v[a] == 1)) {
			if (v[b] == 1)
				cout << b;
			else if (v[a] == 1)
				cout << a;
			return 0;
		}
		if (cur == a)
			cur = b;
		else if (cur == b)
			cur = a;
	}
	cout << cur;
	return 0;
}

