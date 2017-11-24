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
#define frr(i,j, n) for(i = j;i >= n;i--)
const int OO = 1e9 + 5;
typedef vector<int> vi;
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define mem(a,b) memset(a,b,sizeof(a))
////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int fa[26], fb[26], fc[26], A[26];

int mk(int fx[26]) {
	int mn = OO;
	forr(i,0,26)
		if (fx[i])
			mn = min(mn, fa[i] / fx[i]);
	return mn;
}

int main() { // dfil
	fl(); //TODO
	string a, b, c;
	cin >> a >> b >> c;
	forr(i,0,sz(a))
		fa[a[i] - 'a']++, A[a[i] - 'a']++;
	forr(i,0,sz(b))
		fb[b[i] - 'a']++;
	forr(i,0,sz(c))
		fc[c[i] - 'a']++;
	string ret = "";
	int mx = mk(fb), mc = 0, s = 0, cc = mk(fc), bc;
	while (cc) {
		for (int i = 0; i < 26; i++)
			fa[i] -= fc[i];
		s++, bc = mk(fb);
		if (mx < s + bc)
			mx = s + bc, mc = s;
		cc = mk(fc);
	}
	cc = mc, bc = mx - cc;
	forr(i,0,bc)
		cout << b;
	forr(i,0,cc)
		cout << c;
	forr(i,0,26)
	{
		string xx(A[i] - bc * fb[i] - cc * fc[i], i + 'a');
		cout << xx;
	}
	return 0;
}
