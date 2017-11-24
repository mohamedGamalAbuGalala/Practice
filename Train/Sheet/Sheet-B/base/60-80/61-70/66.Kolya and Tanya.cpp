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
const int OO = 1e9 + 7;
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;
lli pow(int x, int p, lli ret = 1) {
	forr(i,0,p)
		ret *= x, ret %= OO;
	return ret % OO;
}

int main() { // dfil
	fl(); //TODO
	int n;
	cin >> n;
	cout << ((pow(3, 3 * n) - pow(7, n)) + OO) % OO;
	return 0;
}
