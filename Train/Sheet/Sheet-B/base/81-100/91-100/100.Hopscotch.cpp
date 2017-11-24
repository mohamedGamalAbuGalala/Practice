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
#define iln() scanf("\n")		//scan new line
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int a, x, y, yy;
	cin >> a >> x >> y;
	if (y % a == 0)
		return puts("-1"), 0;
	yy = y / a + 1;
	if (yy == 1 or !(yy % 2)) {
		if (x * 2 <= -a or x * 2 >= a)
			return puts("-1"), 0;
		cout << (yy == 1 ? 1 : 3 * yy / 2 - 1);
	} else {
		if (x > -a and x < 0)
			cout << yy / 2 * 3;
		else if (x > 0 and x < a)
			cout << yy / 2 * 3 + 1;
		else
			puts("-1");
	}
	return 0;
}
