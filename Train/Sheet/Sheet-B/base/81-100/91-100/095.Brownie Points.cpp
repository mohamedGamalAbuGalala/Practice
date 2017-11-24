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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

struct Pt {
	int x, y;
};
Pt D[200000];

int main() { // dfil
	fl(); //TODO

	int n, i;
	while (in(n) == 1 and n) {
		forr(i, 0, n and in(D[i].x) and in(D[i].y));
		int mx, my, stan = 0, olli = 0;
		mx = D[n / 2].x, my = D[n / 2].y;
		forr(i,0,n){
			if (D[i].x > mx) {
				if (D[i].y > my)
					stan++;
				if (D[i].y < my)
					olli++;
			}
			if (D[i].x < mx) {
				if (D[i].y > my)
					olli++;
				if (D[i].y < my)
					stan++;
			}
		}
		ot(stan), sp(), ot(olli), ln();
	}
	return 0;
}
