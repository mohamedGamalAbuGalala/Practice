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
#define in(n) scanf("%d",&n)	//scan int
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define ins(n) scanf("%s",n)	//scan char[]

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int n;
	char s[305][305];
	set<char> dg, fl;
	in(n);
	forr(i,0,n and ins(s[i]))
		forr(j,0,n)
			if (i == j or j == n - i - 1)
				dg.insert(s[i][j]);
			else
				fl.insert(s[i][j]);
	if(sz(dg) == 1 and sz(fl) == 1 and *fl.begin() != *dg.begin())
		puts("YES");
	else
		puts("NO");
	return 0;
}
