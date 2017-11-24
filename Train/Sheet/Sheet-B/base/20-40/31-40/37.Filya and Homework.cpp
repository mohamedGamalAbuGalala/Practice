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
void ot(int x) {
	printf("%d ", x);
}
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e5 + 5;
typedef long long int lli;
typedef vector<lli> vi;

int main() {
	file();
	lli n, x;
	set<lli> s;
	set<lli>::iterator si;
	string res = "NO";
	in(n);
	for (int i = 0; i < n and in(x); s.insert(x), ++i)
		;
	int sz = (int) s.size();
	if (sz <= 2)
		res = "YES";
	if (sz == 3) {
		si = s.begin();
		lli f = *si;
		++si;
		lli m = *si;
		++si;
		lli l = *si;
		if ((2 * m) == (f + l))
			res = "YES";
	}
	cout << res;
	return 0;
}
