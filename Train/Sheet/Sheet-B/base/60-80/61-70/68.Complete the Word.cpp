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


void solve() {
	using lli = long long int;
	lli msk = 0;
	string s;
	cin >> s;
	int n = sz(s), f = 0;
	if (n < 26) {
		puts("-1");
		return;
	}

	for (int i = 0; i + 25 < n; i++) {
		msk = 0;
		int cnt = 0;
		for (int j = i, x = 0; x < 26; ++x, j++) {
			if (s[j] != '?')
				msk |= (1 << (s[j] - 'A'));
			else
				cnt++;
		}
		if (cnt == 26 - __builtin_popcount(msk)) {
			vector<int> V;
			for (int j = 0; j < 26; j++) {
				if (msk & (1 << j))
					continue;
				V.pb(char('A' + j));
			}
			for (int j = i, x = 0, z = 0; x < 26; ++x, j++) {
				if (s[j] != '?')
					continue;
				else
					s[j] = V[z++];
			}
			f = 1;
			break;
		}
	}
	for (int i = 0; i < n; i++)
		if (s[i] == '?')
			s[i] = 'A';
	if (f)
		cout << s << "\n";
	else
		cout << "-1\n";

}


int main() { // dfil
	fl(); //TODO
	solve();
	return 0;
}
