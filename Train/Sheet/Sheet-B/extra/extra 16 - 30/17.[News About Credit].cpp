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
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	typedef pair<int, int> ii;
	ii a[1000];
	int n, s = 0;
	cin >> n;
	forr(i,0,n and cin >> a[i].first)
		s += a[i].first, a[i].second = i;
	if (a[0].first == 0 or s < n - 1)
		return cout << -1, 0;
	sort(a + 1, a + n, greater<ii>());
	cout << n - 1 << "\n";
	int i0 = 0;
	forr(i,1,n)
	{
		cout << a[i0].second + 1 << " " << a[i].second + 1 << endl;
		a[i0].first--;
		if (!a[i0].first)
			i0++;
	}
	return 0;
}
