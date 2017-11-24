#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
bool in(long long int &x) {
//	return scanf("%lf", &x);		// double
//	return scanf("%d", &x);			// int
	return scanf("%lld", &x);			// long long int
}
void ot(long long int x) {
//	printf("%d ", x);
	printf("%lld ", x);		//  	long long int
}
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e3 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;

int main() {
	file();
	lli n, m, xs, ys, k, x, y, ans = 0;
	in(n), in(m), in(xs), in(ys), in(k);
	for (lli i = 0; i < k and in(x) and in(y); ++i)
		for (lli cof = 1100000000; cof; cof /= 2)
			while (((xs + x * cof) > 0) and ((xs + x * cof) <= n)
					and ((ys + y * cof) > 0) and ((ys + y * cof) <= m))
				xs += (x * cof), ys += (y * cof), ans += cof;
	ot(ans);
	return 0;
}
