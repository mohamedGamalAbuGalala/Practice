//============================================================================
// Name        : Primes.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int a, b, k, i, j, sum[1000001];
bool vis[1000001];

void seive() {
	for (i = 2; i <= b; ++i)
		if (!vis[i])
			for (j = i + i; j <= b; j += i)
				vis[j] = 1;
	for (i = 2; i <= b; ++i)
		sum[i] = sum[i - 1] + (!vis[i]);
}

bool check(int l) {
	for (i = a; i + l <= b + 1; ++i)
		if (sum[i + l - 1] - sum[i - 1] < k)
			return 0;
	return 1;
}

int bS() {
	int s = 0, e = b - a + 1, ret = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (check(mid))
			e = mid - 1, ret = mid;
		else
			s = mid + 1;
	}
	return ret;
}

int main() {
	cin >> a >> b >> k;
	seive();
	cout << bS() << endl;
	return 0;
}
