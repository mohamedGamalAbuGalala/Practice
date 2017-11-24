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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, a, b;
	in(n);
	while(n-- and in(a) and in(b))
		if(a!= b)
			return puts("Happy Alex"),0;
	puts("Poor Alex");
	return 0;
}
