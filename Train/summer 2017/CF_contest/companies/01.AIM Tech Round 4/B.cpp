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
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back
#define in(n) scanf("%d",&n)	//scan int
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
typedef vector<pair<int, int>> vii;
const int OO = 1e9 + 5;
#define ot(x) printf("%d", x)	//output int

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit
using lli = long long int;

lli ans = 0, pw[105], arr[55][55], p = 1;

void add(int a) {
	ans = (ans + pw[a] - 1);
}
int main() { // dfil
	fl(); //TODO
	int n, m, i, j, ct;
	cin >> n >> m;
	forr(i,0,63)
		pw[i] = p, p *= 2;
	forr(i,0,n)
		forr(j, 0, m and cin>>(arr[i][j]));
	forr(i,0,n)
	{
		ct = 0;
		forr(j,0,m)
			ct += arr[i][j];
		add(ct), add(m - ct);
	}
	forr(i,0,m)
	{
		ct = 0;
		forr(j,0,n)
			ct += arr[j][i];
		add(ct), add(n - ct);
	}
	cout << ans - m * n;
	return 0;
}
