#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
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
const int N = 2e4 + 5;
const int OO = 1e9;
typedef pair<lli, string> lls;

int main() {
	file();
	int t, cases = 0;
	in(t);
	while (t--) {
		int n, tp = 1, x, s = OO, e, sm = 0, ans = 0;
		in(n);
		for (int i = 2; i <= n and in(x); ++i) {
			sm += x;
			if (sm < 0)
				sm = 0, tp = i;
			if (sm >= ans) {
				if (sm > ans || (sm == ans && (i - tp > e - s)))
					s = tp, e = i;
				ans = sm;
			}
		}
		if (ans > 0)
			printf("The nicest part of route %d is between stops %d and %d\n",
					++cases, s, e);
		else
			printf("Route %d has no nice parts\n", ++cases);
	}
	return 0;
}
