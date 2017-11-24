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
	int n, m, k;
	scanf("%d %d \n", &n, &m);
	int ar[n];
	for (int i = 0; i < n && scanf("%d ", &ar[i]); ++i)
		;
	scanf("\n");
	for (int i = 0; i < m && scanf("%d\n", &k); ++i) {
		int idx = (lp(ar, ar + n, k) - ar);
		if (ar[idx] != k)
			cout << -1 << "\n";
		else if (ar[idx] == k)
			cout << idx << "\n";
	}
}
