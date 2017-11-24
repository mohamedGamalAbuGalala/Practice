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

set<char> se;

int main() { // dfil
	fl(); //TODO
	string s;
	int n;
	cin >> s >> n;
	for (auto ch : s)
		se.insert(ch);
	if (n > sz(s))
		puts("impossible");
	else if (n > sz(se))
		ot(n-sz(se));
	else
		ot(0);
	return 0;
}
