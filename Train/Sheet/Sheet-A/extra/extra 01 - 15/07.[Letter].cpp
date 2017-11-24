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

typedef vector<int> vi;
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ln() printf("\n")		//output new line
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
const int OO = 1e9 + 5;
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, m, sx = OO, sy = OO, ex = -1, ey = -1;
	bool ar[55][55];
	char ch;
	in(n), in(m);
	forr(i,0,n)
		forr(j,0,m and cin>>ch)
			ar[i][j] = (ch == '*'),
					(ch == '*') ?
							sx = min(sx, i), sy = min(sy, j), ex = max(ex, i), ey =
									max(ey, j) :
							n + 1 - 1;
	forr(i,sx,ex+1)
	{
		forr(j,sy,ey+1)
			(ar[i][j]) ? cout << '*' : cout << '.';
		ln();
	}
	return 0;
}
