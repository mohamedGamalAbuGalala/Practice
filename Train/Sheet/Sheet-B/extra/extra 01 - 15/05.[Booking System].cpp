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
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define all(v) v.begin(), v.end()

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int k, n;
	typedef pair<pair<int, int>, int> ii;
	typedef pair<int, int> ip;
	ip tb[1111];
	ii a[1111];
	cin >> n;
	forr(i, 0, n and cin>>a[i].F.S >>a[i].F.F)
		a[i].S = i + 1;
	cin >> k;
	forr(i, 0, k and cin>>tb[i].F)
		tb[i].S = i + 1;
	sort(a, a + n), sort(tb, tb + k), reverse(a, a + n);
	int tm = 0;
	typedef vector<ip> vi;
	vi v;
	bool oc[1111] { 0 };
	forr(i,0,n)
	{
		int f = lower_bound(tb, tb + k, ip((a[i].F.S), 0)) - tb;
		while(f < k and oc[f])
			f++;
		if (f < k and !oc[f])
			v.pb(ip(a[i].S, tb[f].S)), tm += a[i].F.F, oc[f] = 1;
	}
	cout << sz(v) << " " << tm << "\n", sort(all(v));
	for (auto it : v)
		cout << it.F << " " << it.S << "\n";
	return 0;
}
