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
#define otl(x) printf("%lld", x)//output long long int
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)
typedef pair<int, int> ii;
using ll = long long int;
#define F first
#define S second
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
int a[600100], ret[600100];
priority_queue<ii> q;

int main() { // dfil
	fl(); //TODO
	int n, k;
	in(n), in(k);
	forr(i, 0, n and in(a[i]));
	forr(i, 0, k + 1 )
		q.push(ii(a[i], i));
	ll mx = 0;
	int ct = k;
	while (sz(q)) {
		ii cur = q.top();
		mx += (ll(ct) - ll(cur.S)) * ll(cur.F);
		q.pop(), ret[cur.S] = ct++;
		if (ct <= n)
			q.push(ii(a[ct], ct));
	}
	otl(mx), ln();
	forr(i,0,n)
		ot(ret[i]+1), sp();
	return 0;
}
