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
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO

	int n, m, pp = 0, x, y;
	char op[2];
	while (in(n) == 1 and in(m)) {
		if (pp)
			puts("\n**********************************\n");
		printf("Problem #%d\n\n", ++pp);
		int H[10][10] { 0 }, V[10][10] { 0 }, Ans[10] { 0 };
		while (m-- and ins(op) and in(x) and in(y))
			(op[0] == 'H') ? H[x][y] = 1 : V[y][x] = 1;

		frr(i,n,0)
			frr(j,n,0)
				H[i][j] ? H[i][j] += H[i][j + 1] : H[i][j] + 1 - 1,
						V[i][j] ? V[i][j] += V[i + 1][j] : V[i][j] + 1 - 1;
		forr(i,1,n+1)
			forr(j,1,n+1)
				frr(k,min(H[i][j],V[i][j]),1)
					if (H[i + k][j] >= k and V[i][j + k] >= k)
						Ans[k]++;
		int find = 0;
		forr(i,1,n)
			if (Ans[i])
				printf("%d square (s) of size %d\n", Ans[i], i), find = 1;
		if (!find)
			puts("No completed squares can be found.");
	}
	return 0;
}
