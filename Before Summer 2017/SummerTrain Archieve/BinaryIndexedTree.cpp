// BinaryIndexedTree.cpp : Defines the entry point for the console application.
//	BY	::	BU_GALALA

#include "stdafx.h"
#include <iostream>

using namespace std;

int tree[100000], maxVal = 100000;

int solve(int ind) {
	int ret = 0;
	for (int i = ind; i > 0; i-=(i&(-i))) {
		ret += tree[i];
	}
	return ret;
}
void update(int ind, int val) {
	for (int i = ind; i <= maxVal; i+=(i&(-i))) {
		tree[i] += val;
	}
	return;
}

int main()
{
	update(1, 10);
	solve(4);	//sum  0 --> ind
	return 0;
}

