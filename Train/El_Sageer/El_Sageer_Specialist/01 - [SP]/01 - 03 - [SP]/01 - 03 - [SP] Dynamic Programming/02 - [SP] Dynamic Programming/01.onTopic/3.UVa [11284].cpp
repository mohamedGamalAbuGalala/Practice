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
#define inc(n) scanf("%c ",&n)	//scan char
#define mem(a,b) memset(a,b,sizeof(a))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
const int OO = 1e9 + 5;
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int T, n, m, dist[55][55], dp[55][1 << 12], u, v, p, cd, cc, sm, sv[55], mp[55];
bool adj[55][55];
char jnk;

int tsp(int pos, int bmsk) { // tsp on shops have cd we want to buy which is <= 12
	if (bmsk == (1 << p) - 1)
		return -dist[pos][0];

	int &ret = dp[pos][bmsk];
	if (ret == -1) {
		ret = -dist[pos][0];
		forr(nxt,0,n)
			if (mp[nxt] != -1 and !isOn(bmsk, mp[nxt]))
				setBit(bmsk,mp[nxt]), ret = max(ret,
						sv[nxt] - dist[pos][nxt] + tsp(nxt, bmsk)), clearBit(
						bmsk, mp[nxt]);
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	in(T);
	while (T-- and in(n) and in(m)) {
		n++, sm = 0, mem(mp, -1), mem(dp, -1), mem(adj, 0), mem(sv, 0), mem(
				dist, 5);
		forr(i,0,m and cin>>u>>v>>cd>>jnk>>cc)
		{
			int cost = cd * 100 + cc;
			if (adj[u][v])
				cost = min(cost, dist[u][v]);
			dist[u][v] = dist[v][u] = cost, adj[u][v] = adj[v][u] = 1;
		}

		forr(k,0,n)
			forr(i,0,n)
				forr(j,0,n)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		forr(i,0,n)
			dist[i][i] = 0;
		in(p);
		forr(i,0,p and cin>>u>>cd>>jnk>>cc)
		{
			int cost = cd * 100 + cc;
			sv[u] = cost, mp[u] = i;
		}
		int mx = tsp(0, 0);
		if (!mx)
			puts("Don't leave the house");
		else
			printf("Daniel can save $%.2lf\n", double((mx * 1.0) / 100));
	}
	return 0;
}
