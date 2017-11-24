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

const lli N = 1e2;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

bool cmp(pair<char, int> b, pair<char, int> a) {
	if (a.second > b.second)
		return 1;
	else if (a.second == b.second)
		if (a.first > b.first)
			return 1;
	return 0;
}

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		string inp;
		cin >> inp;
		map<char, int> m;
		vector<pair<char, int>> v;
		for (int i = 0; i < (int) inp.size(); ++i) {
			if (!m[inp[i]])
				m[inp[i]] = 1;
			else
				m[inp[i]]++;
		}
		for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
			pair<char, int> tmp;
			tmp.first = it->first;
			tmp.second = it->second;
			v.pb(tmp);
		}
		sort(v.begin(), v.end(), cmp);
		int si = v.size();
		if (si & 1)
			cout << v[si / 2].first << "\n";
		else
			cout << v[si / 2 - 1].first << v[si / 2].first << "\n";
	}
	return 0;
}
