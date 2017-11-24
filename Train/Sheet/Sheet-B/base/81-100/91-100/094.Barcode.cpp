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
#define iln() scanf("\n")		//scan new line
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int f[1111][3];
int col[1111], to0[1111], to1[1111];
int need, n, m, x, y;

int main() { // dfil
	fl(); //TODO
	in(n), in(m), in(x), in(y);
	forr(i,0,n)
		forr(j,0,m)
		{
			char ch = getchar();
			while (ch != '.' and ch != '#')
				ch = getchar();
			col[j] += (ch == '#');
		}
	forr(i,0,m)
		to0[i] = col[i], to1[i] = n - col[i];
	mem(f,10), f[0][0] = 0, f[0][1] = 0;
	forr(j,0,m)
		forr(q,0,2)
			if (f[j][q] < 1e7) {
				need = 0;
				forr(i,j,m)
				{
					if (!q)
						need += to1[i];
					else
						need += to0[i];
					if (i - j + 1 >= x and i - j + 1 <= y)// if no constraints it will be simple dp and out = 9 for sample
						f[i + 1][1 - q] = min(f[i + 1][1 - q], f[j][q] + need);
					else
						break;
				}
			}
	ot(min(f[m][0], f[m][1]));
	return 0;
}
