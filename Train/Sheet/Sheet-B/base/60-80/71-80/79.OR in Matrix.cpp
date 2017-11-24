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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, m, b[105][105];
	using vi = vector<int>;
	vector<vi> a;
	cin >> n >> m, a.assign(n, vi(m, 1));
	forr(i,0,n)
		forr(j,0,m and cin>>b[i][j])
			if (!b[i][j]) {
				forr(k,0,n)
					a[k][j] = 0;
				forr(k,0,m)
					a[i][k] = 0;
			}
	forr(i,0,n)
		forr(j,0,m)
			if (b[i][j]) {
				bool don = 0;
				forr(k,0,n)
					if (a[i][k] or a[k][j])
						don = 1;
				if (!don)
					return puts("NO"), 0;
			} else {
				forr(k,0,n)
					if (a[i][k] or a[k][j])
						return puts("NO"), 0;
			}
	puts("YES");
	for (auto ii : a) {
		for (auto jj : ii)
			cout << jj << " ";
		puts("");
	}
	return 0;

}
