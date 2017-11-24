#include <bits/stdc++.h>

#define INF 1e18
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

const lli maxN = 10000;
const lli maxE = 1e5 + 10;

int n;
string ss[51];
int alph[51][27], res[51];

int solve(string cur, string s) {
	int res = 0;
	int tmp = 0;
	while (cur != s && tmp < (int) s.size()) {
		s = s.substr(1).append(s.substr(0, 1));
		res++, tmp++;
	}
	if (tmp == (int) s.size())
		return -1;
	return res;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	int ls = 0, f = 0;
	for (int i = 0; i < n; ++i) {
		cin >> ss[i];
		for (int j = 0; j < (int) ss[i].size(); ++j) {
			int ind = ss[i][j] - 'a';
			alph[i][ind]++;
		}
		if (!f) {
			ls = ss[i].size();
			f++;
			continue;
		}
		int tmp = ss[i].size();
		if (ls == tmp)
			continue;
		cout << -1;
		return 0;
	}
	bool same = 1;
	for (int i = 0; i < 27 && same; ++i) {
		int cur = alph[0][i];
		for (int j = 1; j < n && same; ++j) {
			if (alph[j][i] != cur)
				same = 0;
		}
	}
	if (!same) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		int rs = 0;
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			int tt = solve(ss[i], ss[j]);
			if (tt == -1) {
				cout << -1;
				return 0;
			}
			rs += tt;
		}
		res[i] = rs;
	}
	int mn = res[0];
	for (int i = 1; i < n; ++i) {
		mn = min(res[i], mn);
	}
	cout << mn;
	return 0;
}
