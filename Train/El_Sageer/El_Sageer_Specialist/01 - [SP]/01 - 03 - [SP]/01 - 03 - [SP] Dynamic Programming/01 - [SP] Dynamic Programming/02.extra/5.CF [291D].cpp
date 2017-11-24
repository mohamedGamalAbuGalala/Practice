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
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define mem(a,b) memset(a,b,sizeof(a))
#define ln() printf("\n")		//output new line
#define sp() printf(" ")		//output single space

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int n, k;
int a[11234];

int main() { // dfil
	fl(); //TODO
	in(n), in(k);
	forr(i,1,n+1)
		a[i] = min(n, i + 1), ot(a[i]), sp();
	ln();
	int sh = 1;
	forr(i,1,k)
	{
		forr(j,1,n+1)
			a[j] = (sh + j) <= n ? a[(sh + j)] : n, ot(a[j]), sp();
		ln(), sh <<= 1;
	}
	return 0;
}
