//============================================================================
// Name        : Aggressive.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int stalls[100001], c, n;
bool check(int gap) {
	int pre = stalls[0], i, cnt = 1;
	for (i = 1; i < n; ++i)
		if (stalls[i] >= pre + gap)
			pre = stalls[i], cnt++;
	return cnt >= c;
}

int main() {
	int t, i;
	cin >> t;
	while (t--) {
		cin >> n >> c;
		for (i = 0; i < n && cin >> stalls[i]; ++i)
			;
		sort(stalls, stalls + n);
		int s = 0, e = 1e9, ret = 0;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (check(mid))
				s = mid + 1, ret = mid;
			else
				e = mid - 1;
		}
		cout << ret << endl;
	}
	return 0;
}
