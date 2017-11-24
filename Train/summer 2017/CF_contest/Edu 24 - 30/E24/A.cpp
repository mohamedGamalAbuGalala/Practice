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
	lli n, k, w, d, c, nw;
	in(n), in(k);
	w = n / 2;
	d = w / (k + 1);
	c = d * k;
	nw = n - (d + c);
	ot(d), ot(c), ot(nw);
	return 0;
}
