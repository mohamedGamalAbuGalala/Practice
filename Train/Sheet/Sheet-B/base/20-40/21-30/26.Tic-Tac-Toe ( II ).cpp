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

int main() {
	file();
	string inp;
	while (cin >> inp && inp != "end") {
		char g[3][3];
		int xwin = 0, owin = 0, axis = 0, oos = 0;

		int curinp = 0;
		// horizental
		for (int i = 0; i < 3; ++i) {
			for (int l = 0; l < 3; ++l)
				g[i][l] = inp[curinp++];
			bool x = 0, o = 0;
			char cur = g[i][0];
			if (cur == 'X')
				x = 1;
			if (cur == 'O')
				o = 1;
			int j;
			for (j = 1; j < 3; ++j)
				if (g[i][j] != cur)
					break;
			if (j == 3 && x)
				xwin++;
			if (j == 3 && o)
				owin++;

			for (j = 0; j < 3; ++j) {
				if (g[i][j] == 'X')
					axis++;
				if (g[i][j] == 'O')
					oos++;
			}
		}

		// vertical
		for (int i = 0; i < 3; ++i) {

			bool x = 0, o = 0;
			char cur = g[0][i];
			if (cur == 'X')
				x = 1;
			if (cur == 'O')
				o = 1;
			int j;
			for (j = 1; j < 3; ++j)
				if (g[j][i] != cur)
					break;

			if (j == 3 && x)
				xwin++;
			if (j == 3 && o)
				owin++;
		}

		// diagonal right to left
		bool x = 0, o = 0;
		char cur = g[0][0];
		if (cur == 'X')
			x = 1;
		if (cur == 'O')
			o = 1;
		int j;
		for (j = 1; j < 3; ++j)
			if (g[j][j] != cur)
				break;

		if (j == 3 && x)
			xwin++;
		if (j == 3 && o)
			owin++;

		// diagonal left to right
		x = 0, o = 0;
		cur = g[0][2];
		if (cur == 'X')
			x = 1;
		if (cur == 'O')
			o = 1;
		for (j = 1; j < 3; ++j)
			if (g[j][2 - j] != cur)
				break;

		if (j == 3 && x)
			xwin++;
		if (j == 3 && o)
			owin++;

		if (((axis - oos) > 1) || (oos > axis) || (xwin > 0 && owin > 0)) {
			cout << "invalid\n";
			continue;
		}
		if (owin == 0 && xwin == 0 && (axis + oos) != 9) {
			cout << "invalid\n";
			continue;
		}
		if (owin > 0 && axis != oos) {
			cout << "invalid\n";
			continue;
		}
		if (xwin > 0 && ((axis - oos) != 1)) {
			cout << "invalid\n";
			continue;
		}
		cout << "valid\n";
	}
	return 0;
}
/*
 Notes::


 XOX
 OXO
 XOX
 xwin can be > 1

 if (((axis - oos) > 1) || (axis > oos + 1) || (oos > axis) || xwin > 1
 || owin > 1 || (xwin > 0 && owin > 0)) {
 cout << "no\n";
 continue;
 }
 if (owin > 0 && axis != oos) {
 cout << "no\n";
 continue;
 }
 if (xwin > 0 && ((axis - oos) != 1)) {
 cout << "no\n";
 continue;
 }

 Input::

 Output::


 */
