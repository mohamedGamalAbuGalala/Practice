/*
 Notes::


		if (owin == 0 && xwin == 0 && (axis + oos) != 9) {
			cout << "invalid\n";
			continue;
		}

 Input::

XXXOO.XXX
XOXOXOXOX
OXOXOXOXO
XXOOOXXOX
XO.OX...X
.XXX.XOOO
OOXXXOOXO

 Output::
invalid
valid
invalid
valid
valid
invalid
invalid

 */
#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
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
