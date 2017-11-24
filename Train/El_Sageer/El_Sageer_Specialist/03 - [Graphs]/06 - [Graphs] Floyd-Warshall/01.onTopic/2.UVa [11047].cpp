#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define forr(i,j, n) for(int i = j;i < n;i++)
#define in(n) scanf("%d",&n)	//scan int
#define pb push_back
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

map<string, int> sti;
map<int, string> its;
int dst[105][105], p[105][105], path[105][105], T, n, q, OO = 912345678;
typedef vector<int> vi;
vi pth;

void build_path(int src, int dest) {
	if (path[src][dest] == -1)	//So this is the last way
			{
		pth.pb(src);
		return;
	}
	build_path(src, path[src][dest]);
	build_path(path[src][dest], dest);
}

void printPath(int i, int j) {
	if (i != j)
		printPath(i, p[i][j]);
	pth.pb(j);
}

int main() { // dfil
	fl(); //TODO
	in(T);
	string s, d;
	while (T-- and in(n)) {
		string nm;
		sti.clear(), its.clear();
		forr(i,0,n and cin>>nm)
			sti[nm] = i, its[i] = nm;
		forr(i,0,n)
		{
			forr(j,0,n and in(dst[i][j]))
			{
				if (dst[i][j] == -1)
					dst[i][j] = OO;
				p[i][j] = i, path[i][j] = -1;
			}
		}

		in(q);
		forr(k,0,n)
			forr(i,0,n)
				forr(j,0,n)
					if (dst[i][k] < OO and dst[k][j] < OO)
						if (dst[i][j] > (dst[i][k] + dst[k][j]))
							dst[i][j] = (dst[i][k] + dst[k][j]), p[i][j] =
									p[k][j], path[i][j] = k;

		while (q-- and cin >> nm >> s >> d) {
			int si = sti[s], di = sti[d];
			if (dst[si][di] != OO) {
				printf("Mr %s to go from %s to %s, you will receive %d euros\n",
						nm.c_str(), s.c_str(), d.c_str(), dst[si][di]);
				pth.clear(), printf("Path:"), build_path(si, di), pth.pb(di);
//				if (si != di)
//					printPath(si, di);
//				else
//					pth.pb(si), printPath(p[si][di], di);
				forr(i,0,sz(pth))
					cout << its[pth[i]] << ((i + 1 < sz(pth)) ? " " : "\n");
			} else
				printf("Sorry Mr %s you can not go from %s to %s\n", nm.c_str(),
						s.c_str(), d.c_str());
		}

	}
	return 0;
}
