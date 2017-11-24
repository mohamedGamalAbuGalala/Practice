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
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define in(n) scanf("%d",&n)	//scan int
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
typedef vector<int> vi;
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int main() { // dfil
	fl(); //TODO
	int n;
	vi v;
	in(n),v.assign(n*2+1,0);;
	forr(i,1,n*2  + 1 and in(v[i]));
	sort(all(v));
	if(v[n] < v[n +1])
		puts("YES");
	else
		puts("NO");
	return 0;
}
