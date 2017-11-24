// MilkThree.cpp : Defines the entry point for the console application.
// by bu-galala
#include "stdafx.h"
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <typeinfo>
#include <vector>
#include <set>
using namespace std;

/*
8 9 10
>>
1
2
8
9
10
*/

int size[3];
int vis[21][21][21];
set<int> ans;

void solve(int a, int b, int c) {
	if (vis[a][b][c])return;
	vis[a][b][c] = 1;
	if (!a) ans.insert(c);
	int arr[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				arr[0] = a; arr[1] = b; arr[2] = c;
				int rem = size[j] - arr[j];
				if (arr[i] < rem) {
					arr[j] += arr[i];
					arr[i] = 0;
				} else {
					arr[j] += rem;
					arr[i] -= rem;
				}
				solve(arr[0], arr[1], arr[2]);
			}
		}
	}
	return;
}
int main(void){
	cin >> size[0] >> size[1] >> size[2];

	solve(0, 0, size[2]);
	while (ans.size()) {
		cout << *ans.begin() << endl;
		ans.erase(ans.begin());
	}
	return 0;
}

