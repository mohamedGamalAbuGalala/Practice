//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include <string>

#define INF 1e18
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 2e8 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

map<char, int> m;

void slv(string a) {
	if (a[1] == '>')
		m[a[0]]++, m[a[2]]--;
	else
		m[a[0]]--, m[a[2]]++;
}

int main() {
	file();
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	slv(s1);
	slv(s2);
	slv(s3);
	string res = "...";
	for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it)
		if (it->second > 0)
			res[2] = it->first;
		else if (it->second < 0)
			res[0] = it->first;
		else
			res[1] = it->first;
	if (res[0] == '.' || res[1] == '.' || res[2] == '.')
		return cout << "Impossible", 0;
	cout << res;
	return 0;
}
