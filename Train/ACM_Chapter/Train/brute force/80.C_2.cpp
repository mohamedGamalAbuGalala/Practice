#include <bits/stdc++.h>
using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
//------------------------------------------------------------------------------Defines

//------------------------------------------------------------------------------

int x, y, z, tmz[3] = { 0 };
vector<pair<int, int>> sols;
vector<vector<int>> likes(10);
map<string, int> mp = { { "Anka", 1 }, { "Chapay", 2 }, { "Cleo", 3 }, {
		"Troll", 4 }, { "Dracul", 5 }, { "Snowy", 6 }, { "Hexadecimal", 7 } };

bool getBit(int num, int idx) {
	return ((num >> idx) & 1) == 1;
}
int cntBits(int msk) {
	int ret = 0;
	while (msk) {
		msk &= (msk - 1);
		ret++;
	}
	return ret;
}

int likings() {
	int cnt = 0;
	for (int t = 0; t < 3; t++) {
		for (int i = 0; i < 7; i++) {
			if (!(getBit(tmz[t], i)))
				continue;
			for (int j = 0; j < 7; j++) {
				if (!(getBit(tmz[t], j)))
					continue;
				if (find(likes[i + 1].begin(), likes[i + 1].end(), j + 1)
						!= likes[i + 1].end())
					cnt++;
			}
		}
	}
	return -cnt;
}

void divide(int tm, int chosen) {
	// Base Case
	if (tm == 3) {
		if (chosen != 127)
			return;
		int a = max(x / cntBits(tmz[0]),
				max(y / cntBits(tmz[1]), z / cntBits(tmz[2])));
		int b = min(x / cntBits(tmz[0]),
				min(y / cntBits(tmz[1]), z / cntBits(tmz[2])));
		sols.push_back(make_pair(a - b, likings()));
		return;
	}

	// Iterations
	for (int msk = 1; msk < 127; msk++) {
		if (msk & chosen)
			continue;
		tmz[tm] = msk;
		divide(tm + 1, chosen | msk);
		tmz[tm] = 0;
	}
}

int main() {
	file(); //TODO
	int n;
	cin >> n;
	string s, t;
	for (int i = 0; i < n; i++) {
		cin >> s >> t >> t;
		likes[mp[s]].push_back(mp[t]);
	}
	cin >> x >> y >> z;
	divide(0, 0);
	sort(sols.begin(), sols.end());
	cout << sols[0].first << " " << -sols[0].second;
	return 0;
}
