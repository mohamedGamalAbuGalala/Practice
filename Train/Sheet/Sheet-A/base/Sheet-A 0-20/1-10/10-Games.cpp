#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;
int main() {
	int n, res = 0, h, a;
	vector<int> home;
	vector<int> away;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h >> a;
		home.pb(h);
		away.pb(a);
	}
	sort(home.begin(), home.end());
	for (int i = 0, s = home.size(); i < s; ++i)
		res += up(home.begin(), home.end(), away[i])
				- lp(home.begin(), home.end(), away[i]);
	cout << res;
	return 0;
}
