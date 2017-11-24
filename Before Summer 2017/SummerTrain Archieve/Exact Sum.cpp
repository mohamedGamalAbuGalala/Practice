//============================================================================
// Name        : Exact.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, f, s, b[10001], l = 0, r, i;
	while (cin >> n) {
		for (i = 0; i < n && cin >> b[i]; ++i)
			;
		cin >> m;
		sort(b, (b + n));

		/*
		 int ind ;
		for (i = 0; i < n && b[i] <= m / 2; i++)
		 {
			ind = lower_bound(b, b + n, m - b[i]) - b;
			if (ind != n && b[ind] == m - b[i])
				f = b[i], s = m - b[i];
		 }
		 */

		r = n - 1;
		while (l < r) {
			while (b[l] + b[r] > m)
				r--;
			while (b[l] + b[r] < m)
				l++;
			if (b[l] + b[r] == m)
				f = b[l++], s = b[r--];
		}

		cout << "Peter should buy books whose prices are " << f << " and " << s
				<< ".\n\n";
	}
	return 0;
}
