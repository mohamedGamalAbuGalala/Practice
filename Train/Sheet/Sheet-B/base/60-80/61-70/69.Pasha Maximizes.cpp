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
int i, j, k;
#define forr(i,j, n) for(i = j;i < n;i++)
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define pb push_back

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	string n;
	int k, mx = 0, jj;
	cin >> n >> k;
	forr(j,0,sz(n) and k)
	{
		mx = n[j], jj = j;
		forr(i,j+1,sz(n)+1 and (i - j) <= k)
			if (n[i] > mx)
				mx = n[i], jj = i;
		if (jj != j and k >= jj - j)
			while (jj != j)
				swap(n[(jj)], n[(jj - 1)]), k--, jj--;
	}
	cout << n;
	return 0;
}
