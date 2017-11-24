//============================================================================
// Name        : A.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
pair<int, int> arr[8];

bool check(int gap) {
	int i, pre = arr[0].first;
	for (i = 1; i < n; ++i) {
		int cur = pre + gap;
		if (cur <= arr[i].first)
			pre = arr[i].first;
		else if (cur > arr[i].first && cur <= arr[i].second)
			pre += gap;
		else
			return 0;
	}
	return 1;
}

int b_s() {
	int s = 0, e = 1440 * 60000, ret;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (check(mid))
			s = mid + 1, ret = mid;
		else
			e = mid - 1;
	}
	return ret;
}

int main() {
	int i, s, e, ans, caseID = 0;
	while (scanf("%d", &n) && n) {
		for (i = 0; i < n; ++i) {
			cin >> arr[i].first >> arr[i].second;
			arr[i].first *= 60000;
			arr[i].second *= 60000;
		}
		sort(arr, arr + n);
		ans = 0;
		do {
			int tmp = b_s();
			ans = (tmp > ans) ? tmp : ans;
		} while (next_permutation(arr, arr + n));
		int sec = round((double) ans / 1000.0);
		int min = sec / 60;
		sec %= 60;
		printf("Case %d: %d:%02d\n", ++caseID, min, sec);
	}
	return 0;
}
