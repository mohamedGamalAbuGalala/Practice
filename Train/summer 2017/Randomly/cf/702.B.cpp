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
bool in(lli &x) {
//	return scanf("%lf", &x);		// double
//	return scanf("%d", &x);			// int
	return scanf("%lld", &x);			// long long int
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
const int N = 1e5 + 5;

lli fct(int n) {
	lli ret = 0;
	for (int i = 1; i <= n; ++i)
		ret += i;
	return ret;
}

int main() {
	file();
	lli n, res = 0, x;
	map<lli, lli> m;
	map<pair<lli, lli>, int> v;
	map<lli, lli>::iterator iti, itj;
	in(n);
	for (int i = 0; i < n and in(x); ++i)
		m[x]++;
	for (iti = m.begin(); iti != m.end(); ++iti)
		for (int i = 0; i < 32; ++i) {
			x = pow(2, i);
			x -= iti->first;
			if (x > 0) {
				itj = m.find(x);
				if (itj != m.end() and !v[ { itj->first, iti->first }]) {
					v[ { iti->first, itj->first }] = 1;
					if (iti->first != itj->first)
						res += iti->second * itj->second;
					else
						res += fct(itj->second - 1);
				}
			}
		}
	cout << res;
	return 0;
}
