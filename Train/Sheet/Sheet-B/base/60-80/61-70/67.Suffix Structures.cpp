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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO

	string s1, s2;
	cin >> s1 >> s2;
	int i = 0, j = 0;
	if (sz(s1) != sz(s2)) {
		int j = 0;
		for(auto ss : s1)
			if (ss == s2[j])
				j++;
		if (j == sz(s2))
			return cout << "automaton", 0;
	}
	int f1[26] { 0 }, f2[26] { 0 };
	for(auto ss : s1)
		f1[ss - 'a']++;
	for(auto ss : s2)
		f2[ss - 'a']++;

	for (int i = 0; i < 26; ++i) {
		if (sz(s1) < sz(s2) and f1[i] and f1[i] != f2[i])
			return cout << "need tree", 0;
		else if (sz(s2) < sz(s1) and f2[i] and f1[i] < f2[i])
			return cout << "need tree", 0;
		else if (sz(s1) == sz(s2) and f1[i] != f2[i])
			return cout << "need tree", 0;
	}
	if (sz(s1) == sz(s2))
		cout << "array";
	else
		cout << "both";
	return 0;
}
