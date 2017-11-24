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
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define otl(x) printf("%lld", x)//output long long int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define min(x,y) x < y ? x : y

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int T, n, m, y[1011], x[1011];
	in(T);
	using lli = long long int;
	lli ans;
	while (T-- and in(m) and in(n)) {
		forr(i, 0, m-1 and in(x[i]));
		forr(i, 0, n-1 and in(y[i]));
		sort(x, x + m - 1, greater<int>()), sort(y, y + n - 1, greater<int>());
		int cx = 0, cy = 0, xp = 1, yp = 1;
		ans = 0, n--, m--;
		while (cx < m or cy < n) {
			if (cx < m and cy < n) {
				if (x[cx] > y[cy])
					ans += x[cx] * yp, xp++, cx++;
				else
					ans += y[cy] * xp, yp++, cy++;
			} else {
				while (cx < m)
					ans += x[cx] * yp, cx++;
				while (cy < n)
					ans += y[cy] * xp, cy++;
			}
		}
		otl(ans), ln();
	}
	return 0;
}
