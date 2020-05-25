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
// input handle
#define iln() scanf("\n")
#define in(n) scanf("%d",&n)
#define inc(n) scanf("%c",&n)
#define otc(x) printf("%c", x)
// helpers defines
#define all(v) v.begin(), v.end()

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int main() { // dfil
	fl(); //TODO
	int n;
	char c;
	string ans = "", con[] = { "", "", "2", "3", "322", "5", "53", "7", "7222",
			"7332" };
	in(n), iln();
	forr(i,0,n and inc(c))
		ans += con[c - '0'];
	sort(all(ans)),reverse(all(ans));
	cout << ans;
	return 0;
}
