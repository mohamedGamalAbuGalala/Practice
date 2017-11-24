#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
bool in(int &x) {
//	return scanf("%lf", &x);		// double
	return scanf("%d", &x);			// int
//	return scanf("%lld", &x);			// long long int
}
void ot(int x) {
	printf("%d ", x);
//	printf("%lld ", x);		//  	long long int
//	printf("%.3lf ", x);
}
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define cl(v,d) memset(v,d,sizeof(v))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e3 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;

vi v;
vector<pair<int, int>> res;
vector<int> l;

int slv(int cur = 0, int ls = -1) {
	if (cur == sz(v) - 1) {
		if (v[cur] > v[ls])
			return 1;
		return 0;
	}
	int ret1 = 0, ret2 = 0;
	if (ls != -1 and v[cur] < v[ls])
		ret2 = slv(cur, l[cur]), ret1 = 0;
	else
		ret1 = 1 + slv(cur + 1, cur), ret2 = 0;
	if (ret2 > ret1)
		res.pb( { ret2, cur });
	else
		res.pb( { ret1, cur });
	return ret1;
}

int main() {
	file();
	int t, x;
	scanf("%d\n\n", &t);
	while (t--) {
		v.clear(), res.clear(), l.clear();
		string s;
		while (getline(cin, s) && s != "") {
			stringstream ss(s);
			ss >> x;
			int ll = -1;
			for (int i = sz(v) - 1; i >= 0 and ll == -1; --i)
				if (v[i] <= x)
					ll = i;
			if (sz(v) >= 1 and x == v[sz(v) - 1])
				continue;
			l.pb(ll), v.pb(x);
		}

		slv();

		sort(all(res));
		int st = res[sz(res) - 1].second, en = res[sz(res) - 1].second
				+ res[sz(res) - 1].first;

		// output
		set<int> ret;
		set<int>::iterator it;
		int ls = st;
		stack<int> ss;
		while (l[ls] != -1)
			ss.push(v[l[ls]]), ls = l[ls];
		while (sz(ss))
			ret.insert(ss.top()), ss.pop();
		for (int i = st; i < en; ++i)
			ret.insert(v[i]);
		it = ret.end();
		int mx = *it + 1;
		for (int i = en; i < sz(v); ++i)
			if (mx < v[i]) {
				int mn = v[i], j = i;
				while (++j < sz(v))
					if (v[j] > mx and v[j] < mn)
						mn = v[j], i = j;
				ret.insert(v[i]), it++, mx = v[i];
			}
		printf("Max hits: %d\n", sz(ret));
		for (it = ret.begin(); it != ret.end(); ++it)
			cout << *it << "\n";
		if (t)
			printf("\n");
	}
	return 0;
}
