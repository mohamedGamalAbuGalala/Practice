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
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, num = -1, den = -1;
	cin >> n;
	forr(i,1,1001)
		forr(j,i+1,1001)
		{
			if (i + j == n and __gcd(i, j) == 1) {
				if (num < j)
					num = max(num, i), den =  j;
			}
		}
	cout << num << " " << den;
	return 0;
}
