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

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
	freopen("coaches.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;
typedef set<string> ss;

const lli N = 1e2;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

void solve(map<string, ss> &dta) {

	map<string, ss>::iterator itData;
	map<string, vector<map<string, ss>::iterator> > cnt;
	map<string, vector<map<string, ss>::iterator> >::iterator itCnt;

	for (itData = dta.begin(); itData != dta.end(); itData++) {
		set<string> &cur = itData->second;
		set<string>::iterator it = cur.begin();
		for (; it != cur.end(); it++) {
			cnt[*it].push_back(itData);
		}
	}

	for (itCnt = cnt.begin(); itCnt != cnt.end(); itCnt++) {
		if (itCnt->second.size() > 1) {
			for (int i = 0; i < (int) itCnt->second.size(); i++) {
				itCnt->second[i]->second.erase(itCnt->first);
			}
		}
	}
	map<int, set<string> > ans;
	for (itData = dta.begin(); itData != dta.end(); itData++) {
		ans[-itData->second.size()].insert(itData->first);
	}

	for (auto a : ans) {
		for (auto b : a.second) {
			printf("%s %d\n", b.c_str(), -a.first);
		}
	}
}
bool isAnyUp(string a) {
	for (int i = 0; i < (int) a.size(); ++i)
		if (isupper(a[i]))
			return 1;
	return 0;
}
int main() {
	file();
	lli T;
	cin >> T;
	while (T--) {
		int n;
		map<string, ss> dtaa;
		string pnm = "", str = "";
		scanf("%d\n", &n);
		while (n--) {
			getline(cin, str);
			if(isAnyUp(str)){
				pnm = str;
				dtaa[pnm];
			} else {
				dtaa[pnm].insert(str);
			}
		}
		solve(dtaa);
	}
	return 0;
}
