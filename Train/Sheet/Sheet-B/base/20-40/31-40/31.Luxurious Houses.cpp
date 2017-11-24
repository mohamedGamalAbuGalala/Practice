#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
bool in(long long int &x) {
	return scanf("%lld", &x);
}
void ot(long long int x) {
	printf("%lld ", x);
}
#define pb push_back
const int N = 1e5 + 5;
typedef long long int lli;
typedef vector<lli> vi;
int main() {
	file();
	lli ar[N], n, lar = 0, cur;
	vi res;
	in(n);
	for (int i = 0; i < n && in(ar[i]); ++i)
		;
	for (int i = n - 1; i >= 0; --i) {
		cur = ar[i];
		if (cur > lar)
			res.pb(0);
		else
			res.pb(lar - cur + 1);
		lar = max(lar, cur);
	}
	while (res.size()) {
		lli lst = res[(int) res.size() - 1];
		ot(lst), res.pop_back();
	}
	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
