#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
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
void ln() {
	scanf("\n");
}
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define cl(v,d) memset(v,d,sizeof(v))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e9 + 5;

typedef pair<lli, string> lls;

vector<int> res;
vi ar;
typedef pair<int, string> ssi;
vector<ssi> memo;
map<string,string> mp;

ssi slv(int i = 0) {
	if (i == sz(ar)) {
		if (!sz(res))
			return ssi(0, "");
		for (int i = 1; i < sz(res); ++i) {
			if (res[i] == res[i - 1]) {
				res.erase(res.begin() + i);
				i--;
				continue;
			}
		}
		int rr = 1, m = res[sz(res) - 1];
		string rs = to_string(m);
		for (int k = sz(res) - 2; k >= 0; --k) {
			if (res[k] < m)
				rr++, rs = to_string(res[k]) + "," + rs, m = res[k];
		}
		return ssi(rr, rs);
	}
//	ssi &ret = memo[i], ret1, ret2;
	ssi ret, ret1, ret2;

//	if (ret.first == -1) {
	res.pb(ar[i]), ret1 = slv(i + 1), res.pop_back();

	ret2 = slv(i + 1);
	ret = (ret1.first > ret2.first) ? ret1 : ret2;
//	}
	return ret;
}

int main() {
	file();
	int t;
	in(t);
	for (int tst = 0; tst < t; ++tst) {
		ln(), ar.clear(), res.clear(), memo.clear();
		string s;
		while (getline(cin, s) && s != "") {
			int x;
			stringstream ss(s);
			ss >> x;
			ar.pb(x), memo.pb( { -1, "" });
		}
		ssi sret = slv();
		printf("Max hits: %d\n", sret.first);
		vector<string> sp;
		string tmp = sret.second;
		for (int k = 0; k < sz(tmp); ++k) {
			if (tmp[k] == ',') {
				cout << "\n";
				continue;
			}
			cout << tmp[k];
		}
		cout << "\n";
		if (tst + 1 < t)
			cout << "\n";
	}
	return 0;
}
/*
4

1
9
3
8
11
4
5
6
4
19
7
1
7

1
6
2
3
5

1
6
2
3
5

1
1
2
3




 * if (i >= sz(ar)) {
 if (!sz(tn))
 return 0;
 vector<string> sp;
 split(tn, ",", sp);
 int mn = atoi(sp[0].c_str());
 for (int i = 1; i < sz(sp); ++i) {
 int cur = atoi(sp[i].c_str());
 if (mn > cur)
 return mn;
 else if (mn < cur)
 mn = cur;
 }
 if (mx < sz(sp)) {
 mx = sz(sp);
 res.clear();
 for (int i = 0; i < sz(sp); ++i) {
 if (sz(res) and res[sz(res) - 1] == sp[i])
 continue;
 res.pb(sp[i]);
 }
 }
 return mx;
 }
 int &ret = memo[i], ret1, ret2;
 if (ret == -1) {
 ret1 = slv(i + 1, tn);
 string nxt = tn + "," + to_string(ar[i]);
 ret2 = slv(i + 1, nxt);
 ret = max(ret1, ret2);
 }
 */
