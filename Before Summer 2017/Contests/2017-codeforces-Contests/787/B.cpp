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
	int n, m;
	bool cancel = 1;
	cin >> n >> m;
	for (int i = 0; i < m && cancel; ++i) {
		int k, mx = 0;
		cin >> k;
		int arp[10010] = { 0 };
		int arm[10010] = { 0 };
		for (int j = 0; j < k; ++j) {
			int tmp;
			cin >> tmp;
			mx = max(mx, max(tmp, -tmp));
			if (tmp > 0)
				arp[tmp] = 1;
			else if (tmp < 0) {
				tmp = -tmp;
				arm[(tmp)] = 1;
			}
		}
		bool contin = 1;
		for (int j = 0; j < mx + 1 && contin; ++j) {
			if (arp[j] && arm[j])
				contin = 0;
		}
		if (!contin)
			continue;
		cancel = 0;
	}
	if (cancel == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}
