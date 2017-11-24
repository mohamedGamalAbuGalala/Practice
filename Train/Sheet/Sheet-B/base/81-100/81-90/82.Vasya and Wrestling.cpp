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

#define in(n) scanf("%lld",&n)
int i, j, k;
#define forr(i,j, n) for(int i = j;i < (int)n;i++)
using lli = long long;
typedef vector<lli> vi;
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	lli n, p1, p2, x, lst;
	vi p, pp;
	in(n), p1 = p2 = 0;
	forr(i,0,n and in(x))
	{
		if (x > 0)
			p1 += x, p.pb(x), lst = 1;
		else
			p2 += (-x), pp.pb(-x), lst = 0;
	}
	if (p1 > p2)
		return puts("first"), 0;
	else if (p1 < p2)
		return puts("second"), 0;
	else {
		p1 = sz(p), p2 = sz(pp);
		forr(i,0,p1)
		{
			if (p[i] > pp[i])
				return puts("first"), 0;
			else if (p[i] < pp[i])
				return puts("second"), 0;
		}
		if (lst)
			return puts("first"), 0;
		else
			return puts("second"), 0;
	}
	return 0;
}
