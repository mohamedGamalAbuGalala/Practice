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
#define mem(a,b) memset(a,b,sizeof(a))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
const int OO = 1e9 + 5;
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int i, j, T, xs, ys, n, x[11], y[11], dist[11][11], dp[11][1 << 11]; // Karel + max 10 beepers

int tsp(int pos, int bmsk) { // bitmask stores the visited coordinates
	if (bmsk == (1 << (n + 1)) - 1)
		return dist[pos][0]; // return trip to close the loop

	int &ret = dp[pos][bmsk];
	if (ret == -1) {
		ret = OO;
		forr(nxt,0,n+1) // O(n) here
			if (nxt != pos and !isOn(bmsk, nxt)) // if coordinate nxt is not visited yet
				setBit(bmsk,nxt), ret = min(ret,
						dist[pos][nxt] + tsp(nxt, bmsk)), clearBit(bmsk, nxt);
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	in(T);
	while (T-- and in(xs) and in(ys) and in(x[0]) and in(y[0]) and in(n)) {
		forr(i,1,n+1) // karel's position is at index 0
			in(x[i]), in(y[i]);
		forr(i,0,n+1) // build distance table
			forr(j,0,n+1)
				dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]); // Manhattan distance
		mem(dp, -1);
		printf("The shortest path has length %d\n", tsp(0, 1)); // DP-TSP
	}
	return 0;
}
