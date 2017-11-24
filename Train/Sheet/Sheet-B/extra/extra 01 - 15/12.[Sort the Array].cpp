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
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

const int N = (int) 1e5 + 5;
int a[N], b[N];

int main() { // dfil
	fl(); //TODO
	int n;
	in(n);
	forr(i,0,n and in(a[i]))
		b[i] = a[i];
	map<int, int> mp;
	sort(b, b + n);
	forr(i,0,n)
		mp[b[i]] = i;
	forr(i,0,n)
		a[i] = mp[a[i]];
	int L = -1, R = -1;
	forr(i,0,n)
		if (a[i] != i) {
			L = i;
			break;
		}
	frr(i,n-1,0)
		if (a[i] != i) {
			R = i;
			break;
		}
	if (L == -1 || R == -1)
		cout << "yes\n" << 1 << " " << 1 << endl;
	else {
		reverse(a + L, a + R + 1);
		int ok = 1;
		forr(i,0,n)
			if (a[i] != i)
				ok = false;
		if (ok)
			cout << "yes\n" << L + 1 << " " << R + 1 << endl;
		else
			cout << "no\n";
	}
	return 0;
}
