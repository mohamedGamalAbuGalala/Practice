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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	string a[5];
	forr(i, 0, 4 and cin>>a[i]);
	forr(i,0,3)
		forr(j,0,3)
		{
			int b = 0;
			forr(k,i,i+2)
				forr(l,j,j+2)
					b += (a[k][l] == '#');
			if (b == 1 or b == 3 or !b or b == 4)
				return puts("YES"), 0;
		}
	puts("NO");
	return 0;
}
