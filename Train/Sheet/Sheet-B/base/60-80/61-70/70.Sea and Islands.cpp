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
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, k;
	cin >> n >> k;
	vector<string> ans(n, "");
	forr(i,0,n)
		forr(j, 0 , n)
			if (((i + j) & 1))
				ans[i] += 'S';
			else if (k)
				ans[i] += 'L', k--;
			else
				ans[i] += 'S';
	if (k)
		puts("NO");
	else {
		puts("YES");
		for (auto v : ans)
			cout << v, puts("");
	}
	return 0;
}
