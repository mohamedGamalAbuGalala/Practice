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
const int MN = 1e5 + 1e1;

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

#define EPS 1e-9
#define ff first
#define ss second

int n, A[MN];

int main() { // dfil
	fl(); //TODO
	in(n);
	forr(i, 0, n and in(A[i]));
	int ans = 0, mx = 1, lo = A[0], hi = A[0], zdf = 1;
	forr(i,1,n)
	{
		if (A[i] == A[i - 1])
			zdf++, mx++;
		else {
			lo = min(lo, A[i]), hi = max(hi, A[i]);
			if (hi - lo > 1) {
				ans = max(ans, mx), mx = 1 + zdf;
				lo = min(A[i], A[i - 1]), hi = max(A[i], A[i - 1]);
			} else
				mx++;
			zdf = 1;
		}
	}
	ot(max(ans, mx));
	return 0;
}
