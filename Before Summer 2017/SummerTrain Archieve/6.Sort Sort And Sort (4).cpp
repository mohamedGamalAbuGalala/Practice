//============================================================================
// Name        : Sort.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[10001];

bool even(int x) {
	if (x < 0)
		x *= -1;
	if (x % 2 == 0)
		return 1;
	return 0;
}
bool odd(int x) {
	if (x < 0)
		x *= -1;
	if (x % 2)
		return 1;
	return 0;
}
bool cmp(pair<int, int> b, pair<int, int> a) {
	if (a.second > b.second)
		return 1;
	if (a.second == b.second) {
		if (odd(b.first) && even(a.first))
			return 1;
		if (odd(b.first) && odd(a.first))
			return a < b;
		if (even(b.first) && even(a.first))
			return a > b;
	}
	return 0;
}

int main() {
	int n, m, i;
	while (scanf("%d %d\n", &n, &m)) {
		if (!n && !m) {
			printf("0 0\n");
			break;
		}
		printf("%d %d\n", n, m);
		for (i = 0; i < n; ++i) {
			scanf("%d\n", &arr[i].first);
			arr[i].second = arr[i].first % m;
		}
		sort(arr, arr + n, cmp);
		for (i = 0; i < n; ++i) {
			printf("%d\n", arr[i].first);
		}
	}
	return 0;
}
