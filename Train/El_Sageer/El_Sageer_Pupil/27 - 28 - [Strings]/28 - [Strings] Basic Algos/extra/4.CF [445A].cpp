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
#define ins(n) scanf("%s",n)	//scan char[]
#define otc(x) printf("%c", x)	//output char
#define ln() printf("\n")		//output new line
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define inc(n) scanf("%c ",&n)	//scan char

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int n, m;
	char ch;
	in(n), in(m), getchar();
	forr(i,0,n)
	{
		forr(j,0,m)
		{
			inc(ch);
			if (ch == '.' and ((i + j) % 2))
				ch = 'W';
			else if (ch == '.' and !((i + j) % 2))
				ch = 'B';
			otc(ch);
		}
		ln();
	}
	return 0;
}
