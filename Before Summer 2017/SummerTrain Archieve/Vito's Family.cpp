//============================================================================
// Name        : Vito's.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, r, d, i, midp, mid, st[501];
	cin >> t;
	while (t--) {
		cin >> r;
		for (i = 0; i < r && cin >> st[i]; ++i)
			;
		sort(st, st + r);
		midp = r / 2;
		if (!(r % 2))
			mid = (st[midp - 1] + st[midp]) / 2;
		else
			mid = st[midp];
		d = 0;
		for (i = 0; i < r; ++i)
			d += abs(st[i] - mid);
		cout << d << endl;
	}
	return 0;
}
