#include <bits/stdc++.h>

#define INF 1e6
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

const lli maxN = 10e6 * 4;
const lli maxE = 1e5 + 10;

int n;
map<string, int> mp;

int solve(string s, int res) {
	mp[s] = 10;
	bool solved = 1;
	for (int i = 0; i < (int) s.size() && solved; ++i)
		if (s[i] == '-')
			solved = 0;
	if (solved)
		return res;
	int ret = INF;
	for (int i = 0; i < (int) s.size(); ++i) {
		string tmp = s;
		for (int j = i; j < i + n && j < (int) s.size(); ++j) {
			if (tmp[j] == '+')
				tmp[j] = '-';
			else
				tmp[j] = '+';
		}
		if (mp[tmp] == 10)
			continue;
		return ret = min(ret, solve(tmp, res + 1));
	}
}

/*
 * int solve(string s, int n) {
 int cntm = 0, res = 0,nn= n;
 bool solved = 0;
 while (!solved) {
 //		I wanna to try to flip next to make -++- to ---+
 for (int i = 0; i < (int) s.size(); ++i) {
 if (cntm == nn) {
 res++;

 for (int j = i - nn; j < i; ++j)
 s[j] = '+';

 cntm = 0;
 }
 if (s[i] == '-')
 cntm++;
 else
 cntm = 0;
 }
 solved = 1;
 for (int i = 0; i < (int) s.size() && solved; ++i)
 if (s[i] == '-')
 solved = 0;
 }
 return -1;
 }
 *
 */

int main() {
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T, tt = 1;
	string s;
	cin >> T;
	while (T--) {
		cin >> s >> n;
		int sol = solve(s, 0);
		if (sol != -1)
			cout << "Case #" << tt++ << ": " << sol << endl;
		else
			cout << "Case #" << tt++ << ": " << "IMPOSSIBLE" << endl;
	}
	return 0;
}

