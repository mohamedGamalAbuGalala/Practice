//============================================================================
// Name        : COWCAR.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	int i, j = 0, cnt = 0, n, m, d, l, cows[50001], way[50001];
	cin >> n >> m >> d >> l;
	for (i = 0; i < n && cin >> cows[i]; ++i)
		;
	sort(cows, cows + n);
	memset(way, 0, sizeof way);
	for (i = 0; i < n; ++i, ++j) {
		if (j == m)
			j = 0;
		if (cows[i] - (d * way[j]) >= l)
			way[j]++, cnt++;
	}
	cout << cnt << endl;
	return 0;
}
