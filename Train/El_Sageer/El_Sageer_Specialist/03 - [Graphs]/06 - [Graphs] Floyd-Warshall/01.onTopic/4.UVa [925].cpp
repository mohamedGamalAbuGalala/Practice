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
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define mem(a,b) memset(a,b,sizeof(a))
typedef vector<int> vi;
#define pb push_back
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define all(v) v.begin(), v.end()

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int n, OO = 912345678;
bool adj[200][200], ret[200][200];

int main() { // dfil
	fl(); //TODO
	int T, m, pre;
	map<string, int> sti;
	map<int, string> its;
	in(T);
	string u, v;
	int uu, vv;
	while (T-- and in(n)) {
		mem(adj, 0), mem(ret, 0), sti.clear(), its.clear();
		forr(i,0,n and cin>>u)
			sti[u] = i, its[i] = u;
		in(m);
		forr(i,0,m and cin>>u>>pre)
			forr(j,0,pre and cin>>v)
			{
				uu = sti[u], vv = sti[v];
				adj[uu][vv] = 1;
			}
		forr(k,0, n)
			forr(i,0, n)
				forr(j,0, n)
					adj[i][j] |= (adj[i][k] and adj[k][j]);
		forr(i,0,n)
			forr(j,0,n)
				forr(k,0,n)
				{
					if (adj[i][j]) {
						bool vpre = 1;
						forr(k,0,n and vpre)
							vpre &= !(adj[i][k] and adj[k][j]);
						ret[i][j] = vpre;
					}
				}
		for (auto it : sti) {
			uu = it.second;
			vector<string> ott;
			forr(i,0,n)
				if (ret[uu][i])
					ott.pb(its[i]);
			if (sz(ott)) {
				cout << it.first << " " << sz(ott), sort(all(ott));
				for (auto itm : ott)
					cout << " " << itm;
				ln();
			}
		}

	}
	return 0;
}
