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
	freopen("out.txt", "w", stdout);
	int t, tt = 0, n;
	double d, k, s;
	cin >> t;
	while (t--) {
		vector<pair<double, double>> ar;

		cin >> d >> n;
		for (int i = 0; i < n; ++i) {
			cin >> k >> s;
			ar.pb(ii(k, s));
		}

		ar.pb(ii(d, 0));

		sort(ar.begin(), ar.end());
		int cur, nxt;
		double time = 0;

		for (int i = 0; i < n; ++i) {
			cur = i, nxt = i;
			while (ar[cur].first == ar[nxt].first
					|| ar[cur].second <= ar[nxt].second)
				nxt++;
			double curd = ar[cur].first, curs = ar[cur].second, nxts =
					ar[nxt].second;
			double ss = ar[cur].second - ar[nxt].second, dd = ar[nxt].first
					- ar[cur].first;
			double ttime = dd / ss;

			// time to reach end
			if (nxt < n) {
				double mpoint = curd + ttime * curs;
				double toend = d - mpoint;
				ttime += toend / nxts;
			}
			time = max(time, ttime);
		}
		// when we can move with 1000 speed on 10m road
//		if (time < 1.0)
//			time = 1.0;
		cout << "Case #" << ++tt << ": ";
		double ans = d / time;
		cout << fixed << setprecision(6) << ans << "\n";
	}
	return 0;
}
