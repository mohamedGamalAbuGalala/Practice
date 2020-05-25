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

int x, y, z;
vector<pair<int, int>> sols;
vector<vector<int>> tmp(3), likes(7);
map<string, int> mp = { { "Anka", 1 }, { "Chapay", 2 }, { "Cleo", 3 }, {
		"Troll", 4 }, { "Dracul", 5 }, { "Snowy", 6 }, { "Hexadecimal", 7 } };

int likings() {
	int cnt = 0;
	for (int t = 0; t < 3; t++)
		for (int i = 0; i < tmp[t].size(); i++)
			for (int j = 0; j < tmp[t].size(); j++) {
				int a = tmp[t][i], b = tmp[t][j];
				if (find(likes[a].begin(), likes[a].end(), b) != likes[a].end())
					cnt++;
			}
	return -cnt;
}

void divide(int hero) {
	// Base Case
	if (hero == 8) {
		if (tmp[0].empty() || tmp[1].empty() || tmp[2].empty())
			return;
		int a = max(x / tmp[0].size(),
				max(y / tmp[1].size(), z / tmp[2].size()));
		int b = min(x / tmp[0].size(),
				min(y / tmp[1].size(), z / tmp[2].size()));
		sols.push_back(make_pair(a - b, likings()));
		return;
	}

	// Iterations
	for (int i = 0; i < 3; i++) {
		tmp[i].push_back(hero); // Mark
		divide(hero + 1);         // Recursive Call
		tmp[i].pop_back();      // Backtrack
	}
}

int main() {
	file(); //TODO
	int n;
	cin >> n;
	string s, t;
	for (int i = 0; i < n and cin >> s >> t >> t; i++)
		likes[mp[s]].push_back(mp[t]);
	cin >> x >> y >> z;
	divide(1);
	sort(sols.begin(), sols.end());
	cout << sols[0].first << " " << -sols[0].second;
	return 0;
}
