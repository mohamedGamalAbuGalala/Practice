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
lli s(lli x) {
	return (x * (x + 1)) / 2;
}
int main() {
	file();
	lli b, m, ans = 0, x, y;
	in(m), in(b);
	for (y = 0; y <= b; ++y) {
		x = (b - y) * m;
		ans = max(ans, (x + 1) * s(y) + (y + 1) * s(x));
	}
	ot(ans);
	return 0;
}
