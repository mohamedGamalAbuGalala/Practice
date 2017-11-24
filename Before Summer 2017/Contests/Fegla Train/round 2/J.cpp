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
	freopen("alost.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 2e4 + 3;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);
/*
 [0 - 99] Newbie
 [100 - 199] Pupil
 [200 - 299] Specialist
 [300 - 399] Expert
 [400 - 499] Candidate Master
 [500 - 599] Master
 [600 - 699] International Master
 [700 - 799] Grandmaster
 [800 - 899] International Grandmaster
 [900 - 1000] Legendary Grandmaster
 *
 */
void split(const string &s, const char* delim, vector<string> & v) {
	// to avoid modifying original string
	// first duplicate the original string and return a char pointer then free the memory
	char * dup = strdup(s.c_str());
	char * token = strtok(dup, delim);
	while (token != NULL) {
		v.push_back(string(token));
		// the call is treated as a subsequent calls to strtok:
		// the function continues from where it left in previous invocation
		token = strtok(NULL, delim);
	}
	free(dup);
}
map<string, pair<int, int>> mp;
void init() {
	mp["Newbie"] = ii(0, 99);
	mp["Pupil"] = ii(100, 199);
	mp["Specialist"] = ii(200, 299);
	mp["Expert"] = ii(300, 399);
	mp["Candidate Master"] = ii(400, 499);
	mp["Master"] = ii(500, 599);
	mp["International Master"] = ii(600, 699);
	mp["Grandmaster"] = ii(700, 799);
	mp["International Grandmaster"] = ii(800, 899);
	mp["Legendary Grandmaster"] = ii(900, 1000);
}
int main() {
	init();
	file();
	int T;
	cin >> T;
	while (T--) {
		vii pre, aft;
		vi pos;
		vector<string> ar[N];
		int n, sol = 0;
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i) {
			string inp;
			getline(cin, inp);
//			cout << inp << "  tssssssssss \n";
			split(inp, " ", ar[i]);
			for (int j = 0; j < (int) ar[i].size(); ++j) {
				if (ar[i][j] == '?') {
					sol = 1;
					// solveeee
				}
			}
			if (sol) {
				lli res = 1;
				for (int i = 0; i < (int)pos.size(); ++i) {
					res *=pos[i];

				}
			}else
				cout<<0<<"\n";		// no missing data
		}
	}
	return 0;
}
