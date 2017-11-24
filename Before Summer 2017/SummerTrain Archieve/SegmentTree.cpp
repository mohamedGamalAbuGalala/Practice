// SegmentTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int tree[250000];

void update(int node, int s, int e, int ind, int newVal) {
	if (ind > e || ind < s) return;
	if (s == e) {
		if (s == ind)
			tree[node] = newVal;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, ind, newVal);
	update((node * 2) + 1, mid + 1, e, ind, newVal);
	tree[node] = tree[node * 2] + tree[(node * 2) + 1];
	return;
}

int solve(int node, int s, int e, int x, int y) {
	if (s > y || e < x) return 0;
	if (s >= x&&e <= y) return tree[node];
	int ret = 0, mid = (s + e) / 2;
	ret += solve(node * 2, s, mid, x, y);
	ret += solve((node * 2) + 1, mid + 1, e, x, y);
	return ret;
}


int main() {
	int n;
	update(1, 0, n - 1, 5, -2);
	solve(1, 0, n - 1, 1, 3);
	return 0;
}

