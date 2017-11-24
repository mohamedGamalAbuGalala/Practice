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

#define sp() printf(" ")		//output single space
typedef vector<int> vi;
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define ln() printf("\n")		//output new line
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define frr(i,j, n) for(i = j;i >= n;i--)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
const int OO = 1e9 + 5;

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

#define EPS 1e-9
#define ff first
#define ss second

int main() { // dfil
	fl(); //TODO
	string a;
	int m, x;
	cin >> a, in(m);
	vi com(sz(a), 0);
	while (m-- and in(x))
		x--, com[x]++, com[sz(a) - x - 1]--;
	forr(i,1,sz(com)/2)
		com[i] += com[i - 1];
	forr(i,0,sz(a)/2)
		if (com[i] & 1)
			swap(a[i], a[sz(a) - i - 1]);
	cout << a;
	return 0;
}
