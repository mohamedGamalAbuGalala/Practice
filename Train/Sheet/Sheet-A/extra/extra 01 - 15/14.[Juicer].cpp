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
#define iln() scanf("\n")		//scan new line
#define in(n) scanf("%d",&n)	//scan int
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c ",&n)	//scan char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define inl(n) scanf("%I64d",&n)	//scan long long int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ots(x) printf("%s", x)	//output char[]  ( be careful using it may have some issue )
#define otc(x) printf("%c", x)	//output char
#define ln() printf("\n")		//output new line
#define otl(x) printf("%I64d", x)//output long long int
#define otf(x) printf("%.12lf", x)// output double/float with 0.00

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

#define od(x) (x&1)? 1 : 0

int main() { // dfil
	fl(); //TODO
	int n, b, d, ans = 0, x, jj = 0;
	in(n), in(b), in(d);
	forr(i,0,n and in(x))
	{
		if (x <= b)
			jj += x;
		if (jj > d)
			ans++, jj = 0;
	}
	ot(ans);
	return 0;
}
