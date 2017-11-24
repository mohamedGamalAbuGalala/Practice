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
	freopen("good.in", "r", stdin);
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

int main() {
	file();
	int T;
	scanf("%d\n", &T);
	while (T--) {
		stack<char> s;
		int lvl[200] = { 0 };
		string inp;
		getline(cin, inp);
		int n = (int) inp.size();
		for (int i = 0; i < n; ++i) {
			char cur = inp[i];
			if (cur == '{') {
				s.push(cur);
				int mx = 1;
				if (inp[i + 1] == ','
						|| (inp[i + 1] < '9' && inp[i + 1] >= '0'))
					while (inp[i + 1] != '}') {
						if (inp[i + 1] == ',')
							mx++;
						i++;
					}
				lvl[(int) s.size()] = max(mx, lvl[(int) s.size()]);
				mx = 1;
				int j = i + 1;
				string cur = ".";
				while (1) {
					if (inp[j] == '}' && cur == ".")
						break;
					else if (inp[j] == '{')
						cur += '{';
					else if (inp[j] == '}')
						cur = cur.substr(0, cur.size() - 1);
					else if (inp[j] == ',' && cur == ".")
						mx++;
					j++;
				}
				lvl[(int) s.size()] = max(mx, lvl[(int) s.size()]);
			} else if (cur == '}')
				s.pop();
		}
		int idx = 1;
		while (lvl[idx]) {
			cout << "[" << lvl[idx++] << "]";
		}
		cout << "\n";
	}
	return 0;
}
