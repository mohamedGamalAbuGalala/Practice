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

int main() {
	freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	if (s.length() == 1) {
		cout << "YES";
		return 0;
	}
	int res = 0;
	int l = 0, r = s.length() - 1;
	while (l < r) {
		if (s[l] == s[r]) {
			l++, r--;
			continue;
		}
		l++, r--, res++;
	}
	int ln = (int) s.size();
	if ((ln & 1) && res == 0) {
		cout << "YES";
		return 0;
	}
	if (res == 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
