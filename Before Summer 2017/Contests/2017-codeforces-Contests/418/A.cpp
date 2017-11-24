//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
// Description : Hello World in C++, Ansi-style
//============================================================================

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
typedef vector<vector<ii> > vvii;

const lli maxN = 10000;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

int k, n, nn[105], i;
vi kk, vk;

int fl(int p) {
	int j, ret;
	for (j = kk.size() - 1; j >= 0 && kk[j] > p; j--)
		;
	if (j >= 0) {
		ret = kk[j];
		kk.erase(kk.begin() + j);
	} else {
		ret = kk[kk.size() - 1];
		kk.erase(kk.begin() + kk.size() - 1);
	}
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> k;
	bool zeros = 1;
	for (i = 0; i < n; ++i) {
		cin >> nn[i];
		if (nn[i])
			zeros = 0;
	}
	if (zeros) {
		cout << "YES";
		return 0;
	}
	for (i = 0; i < k; ++i) {
		int tmp;
		cin >> tmp;
		kk.pb(tmp);
		vk.pb(1);
	}
	sort(kk.begin(), kk.end());
	if (!nn[0]) {
		nn[0] = kk[kk.size() - 1];
		kk.erase(kk.begin() + kk.size() - 1);
	}
	for (i = 0; i < n; ++i) {
		if (!nn[i]) {
			int l = nn[i - 1];
			int nxt = fl(l);
			nn[i] = nxt;
			if (nn[i] < nn[i - 1]) {
				cout << "YES";
				return 0;
			}
		}
	}
	for (i = 0; i < n - 1; ++i) {
		if (nn[i] > nn[i + 1]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
