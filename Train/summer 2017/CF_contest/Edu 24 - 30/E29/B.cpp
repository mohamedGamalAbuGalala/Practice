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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int a[101], n, mnIns = 99999999;
	cin >> n, n *= 2;
	forr(i, 0, n and cin>>a[i]);
	sort(a, a + n);
	forr(i,0,n)
		forr(j,0,n)
			if (i != j) {
				int ans = 0, f = -1, s = -1;
				forr(k,0,n)
				{
					if (k == i or k == j)
						continue;
					if (f == -1)
						f = a[k];
					else if (s == -1)
						s = a[k];
					else
						ans += (s - f), f = -1, s = -1, k--;
				}
				if (f != -1 and s != -1)
					ans += (s - f);
				mnIns = min(mnIns, ans);
			}
	cout << mnIns;
	return 0;
}
