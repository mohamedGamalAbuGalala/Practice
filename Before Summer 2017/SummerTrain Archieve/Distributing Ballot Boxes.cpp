//============================================================================
// Name        : Distributing.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int pop[500001], n, b;
bool check(int heavy) {
	int i, cnt = 0, cur = 0;
	for (i = 0; i < n; ++i) {
		cur = pop[i];
			while (cur > heavy)
				cur -= heavy, cnt++;
		cnt++;
	}
	return cnt <= b;
}

int main() {
	int i;
	while (cin >> n >> b && n != -1 && b != -1) {
		for (i = 0; i < n && cin >> pop[i]; ++i)
			;
		sort(pop, pop + n);
		int s = 0, e = 5e6, ret = 0;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (check(mid)) {
				e = mid - 1, ret = mid;
			}
			else
				s = mid + 1;
		}
		cout << ret << "\n \n";
	}
	return 0;
}
