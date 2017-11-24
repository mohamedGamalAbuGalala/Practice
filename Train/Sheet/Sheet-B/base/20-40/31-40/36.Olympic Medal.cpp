#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
bool in(double &x) {
	return scanf("%lf", &x);
}
void ot(int x) {
	printf("%d ", x);
}
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 5e3 + 5;
typedef long long int lli;
typedef vector<lli> vi;

int main() {
	file();
	double n, r = 0, m, p1[N] { 0 }, k, p2[N] { 0 }, a, b;
	in(n);
	for (int i = 0; i < (int)n and in(a); r = max(r, a), ++i)
		;
	in(m);
	for (int i = 0; i < (int)m and in(p1[i]); ++i)
		;
	in(k);
	for (int i = 0; i < (int)k and in(p2[i]); ++i)
		;
	in(a), in(b);
	double res = 0;
	for (int i = 0; i < (int)m; ++i)
		for (int j = 0; j < (int)k; ++j)
			res = max(res,r*sqrt((b*p1[i])/((a*p2[j])+b*p1[i])));
	printf("%.12lf", res);
	return 0;
}
