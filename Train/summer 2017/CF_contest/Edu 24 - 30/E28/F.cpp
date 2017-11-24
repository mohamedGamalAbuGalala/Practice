#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define in(n) scanf("%d",&n)	//scan int
#define forr(i,j, n) for(int i = j;i < n;i++)
const int MN = 1e6 + 1e1;
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define otf(x) printf("%.6lf", x)// output double/float with 0.00

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
//int n, res = 1, a[MN];
//set<int> se;

using ll = long long int;
const int N = 1e6 + 3;
int cnt[N];
int n, arr[N];
int last[N];
int nxt[N];
ll cur, tot;

int main() { // dfil
	fl(); //TODO
	in(n);
	forr(i,0,N)
		last[i] = n;
	forr(i, 0, n and in(arr[i]));
	for (int i = n - 1; i >= 0; i--) {
		nxt[i] = last[arr[i]];
		last[arr[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		if (!cnt[arr[i]]++)
			cur++;
		tot += cur;
	}
	cur = tot;
	for (int i = 1; i < n; i++) {
		int j = nxt[i - 1];
		cur--;
		cur -= j - i;
		tot += cur;
	}
	tot = tot * 2 - n; // one element counted once, rest counted twice
	ll ways = 1LL * n * (n + 1) / 2;
	ways = ways * 2 - n;
	otf(1.0 * tot / ways);
	return 0;
}
