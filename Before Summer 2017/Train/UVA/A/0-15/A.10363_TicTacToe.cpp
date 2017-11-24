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
#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d\n", &T);
	while (T--) {
		char g[3][3];
		int xwin = 0, owin = 0, axis = 0, oos = 0;

		// horizental
		for (int i = 0; i < 3; ++i) {
			cin >> g[i];
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
		cout << "yes\n";
	}
	return 0;
}
