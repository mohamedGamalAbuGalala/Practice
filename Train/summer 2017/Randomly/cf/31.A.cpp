#include <bits/stdc++.h>
using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
//------------------------------------------------------------------------------Defines

#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define forr(i,j, n) for(int i = j;i < n;i++)

//------------------------------------------------------------------------------
int main() {
	file(); //TODO
	int n, a[101], x, y, z;
	in(n);
	forr(i, 0, n and in(a[i]));
	forr(i,0,n)
	{
		x = a[i];
		forr(j,0,n)
		{
			if (i == j)
				continue;
			y = a[j];
			forr(k,0,n)
			{
				if (i == k or j == k)
					continue;
				z = a[k];
				if (x == (y + z))
					return (ot(i+1), sp(), ot(j + 1), sp(), ot(k + 1)), 0;
			}
		}
	}
	ot(-1);
	return 0;
}
