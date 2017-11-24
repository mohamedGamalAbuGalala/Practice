//============================================================================
// Name        : Working.cpp
// Author      : abu-galala
// Version     :
// Copyright   : @bu_galala
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

#define INF 1e18
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const lli N = 1e5 + 5;
const lli maxE = 1e5 + 10;
const lli MOD = 1e9 + 7;
const double GOLDEN_RATIO = ((1 + sqrt(5)) / 2);

//string slv(string n) {
//	for (int i = 0; i < (int) n.size() - 1; ++i)
//		if (n[i] == 'x' && n[i + 1] == 'y') {
//			n.erase(i, (i == 0) ? i + 2 : i + 1);
//			n = slv(n);
//		}
//	return n;
//}
//string slv1(string n) {
//	for (int i = 0; i < (int) n.size() - 1; ++i)
//		if (n[i] == 'y' && n[i + 1] == 'x') {
//			swap(n[i], n[i + 1]);
//			n = slv1(n);
//		}
//	return n;
//}
int main() {
	file();
	string n;
	cin >> n;
	int x = 0, y = 0, nn = (int) n.size();
	for (int i = 0; i < nn; ++i)
		(n[i] == 'x') ? x++ : y++;
	if (x > y) {
		string ans((x - y), 'x');
		cout << ans;
	} else {
		string ans((y - x), 'y');
		cout << ans;
	}

//	int x = 0;
//	for (int i = 0; i < (int) n.size(); ++i)
//		if (n[i] == 'x')
//			swap(n[x++], n[i]);
//	int l = x - 1, r = x;
//	if (l < 0)
//		return cout << n, 0;
//	while (l > -1 && r < (int) n.size() && n[l] == 'x' and n[r] == 'y')
//		l--, r++;
//	if (l == -1)
//		return cout << n.substr(r), 0;
//	else if (r == (int) n.size())
//		return cout << n.substr(0, l + 1), 0;
//
	//	n = slv1(n);
//	n = slv(n);
//	cout << n;
	return 0;
}
/*
 scanf("%[^\n]%c",n);
 */
