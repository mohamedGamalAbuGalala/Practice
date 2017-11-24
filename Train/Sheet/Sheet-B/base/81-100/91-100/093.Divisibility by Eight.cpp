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
#define frr(i,j, n) for(int i = j;i >= n;i--)
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	string x;
	cin >> x;
	forr(i,0,sz(x))
	{
		int dv = x[i] - '0';
		if (!(dv % 8))
			return puts("YES"), cout << dv, 0;
		forr(j,i+1,sz(x))
		{
			dv *= 10, dv += x[j] - '0';
			if (!(dv % 8))
				return puts("YES"), cout << dv, 0;
			forr(k,j+1,sz(x))
			{
				dv *= 10, dv += x[k] - '0';
				if (!(dv % 8))
					return puts("YES"), cout << dv, 0;
				dv /= 10;
			}
			dv /= 10;
		}
	}
	puts("NO");
	return 0;
}
