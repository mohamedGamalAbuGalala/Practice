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

#define sp() printf(" ")		//output single space
typedef vector<int> vi;
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ln() printf("\n")		//output new line
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
const int OO = 1e9 + 5;
const int MN = 1e5 + 1e1;

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

#define EPS 1e-9
#define ff first
#define ss second

int main() { // dfil
	fl(); //TODO
	int w[105], n, m, x, y;
	in(n);
	forr(i, 1, n+1 and in(w[i]));
	in(m);
	while (m-- and in(x) and in(y))
		w[x - 1] += y - 1, w[x + 1] += w[x] - y, w[x] = 0;
	forr(i,1,n+1)
		ot(w[i]), ln();
	return 0;
}
