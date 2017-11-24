#include <bits/stdc++.h>
using namespace std;
// input handle
#define in(n) scanf("%d",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d ", x)
#define ln() printf("\n")
#define otl(x) printf("%lld ", x)
#define otf(x) printf("%.2lf ", x)
// helpers defines
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//helpers
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
// constants
const int MN = 2e6 + 1e3;
const int MW = 1e3 + 5;
const int OO = 1e9 + 5;
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<lli, string> lls;

char arr[MN] = { };
map<int, bool> mp;
map<int, bool>::iterator it, it2;
int main() {
	file();

	int n, t, x, maxx = 0;
	in(n);
	string s;
	for (int i = 0; i < MN; mp[i] = 1, i++)
		;
	for (int i = 0; i < n; i++) {
		cin >> s, in(t);
		for (int h = 0; h < t; h++) {
			in(x),x--;
			it = mp.lower_bound(x);
			while (it->first < x + sz(s)) {
				arr[it->first] = s[it->first - x];
				maxx = max(it->first, maxx);
				it2 = it;
				it++;
				mp.erase(it2);
			}
		}
	}
	for (int i = 0; i <= maxx; i++)
		if (arr[i] == 0)
			printf("a");
		else
			printf("%c",arr[i]);
	ln();
	return 0;
}
