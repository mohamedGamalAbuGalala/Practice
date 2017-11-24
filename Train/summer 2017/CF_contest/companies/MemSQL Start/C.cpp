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
#define mem(a,b) memset(a,b,sizeof(a))
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int memo[55], n, arr[55], acc[55];

int solve(int ind) {
	if (ind == n)
		return 0;
	int& res = memo[ind];
	if (res == -1)
		res = max(solve(ind + 1), arr[ind] + acc[ind + 1] - solve(ind + 1));
	return res;
}

int main() { // dfil
	fl(); //TODO
	mem(memo, -1);
	cin >> n;
	forr(i, 0, n and cin >> arr[i]);

	frr(i,n-1,0)
		acc[i] = acc[i + 1] + arr[i];
	cout << acc[0] - solve(0) << ' ' << solve(0);
	return 0;
}
