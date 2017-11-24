//============================================================================
// Name        : Database.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int math = 0;
bool cmp(pair<long int, long int> b, pair<long int, long int> a) {
	if (b.second == a.second) {
		if (a.first == b.first) {
			math++;
		}
		return a.first > b.first;
	}
	return b.second > a.second;
}
int main() {
	long int x;
	bool res[100];
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		long int n, r;
		pair<long int, long int> IC[100000];
		scanf("%d %d", &n, &r);
		for (int j = 0; j < r; j++)
			scanf("%d %d", &IC[j].first, &IC[j].second);
		res[i] = 1;
		sort(IC, IC + r, cmp);
		if (math > 0)
			res[i] = 0;
		math = 0;
	}
	for (int i = 0; i < x; i++) {
		if (res[i] == 0) {
			cout << "Scenario #" << i + 1 << ": impossible" << endl;
		} else {
			cout << "Scenario #" << i + 1 << ": possible" << endl;
		}
	}
	return 0;
}
