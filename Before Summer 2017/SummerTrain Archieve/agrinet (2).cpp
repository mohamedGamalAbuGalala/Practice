//============================================================================
// Name        : AGRINET.cpp
// Author      : Akram
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
	int i, j, cost;
};

int n, cnt = 0, Parent[100], Rank[100], grid[100][100];
edge arr[10001];

bool cmp(edge a, edge b) {
	if (a.cost != b.cost)
		return a.cost < b.cost;
	if (a.i != b.i)
		return a.i < b.i;
	return a.j < b.j;
}

int Find(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find(Parent[node]);
}

void merge(int xRoot, int yRoot) {
	if (Rank[xRoot] < Rank[yRoot])
		Parent[xRoot] = yRoot;
	if (Rank[xRoot] > Rank[yRoot])
		Parent[yRoot] = xRoot;
	if (Rank[xRoot] == Rank[yRoot]) {
		Parent[yRoot] = xRoot;
		Rank[xRoot]++;
	}
	return;
}

int main() {
	FILE *fin = fopen("agrinet.in", "r");
	FILE *fout = fopen("agrinet.out", "w");
	int i, j;
	fscanf(fin, "%d\n", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			edge temp;
			temp.i = i;
			temp.j = j;
			fscanf(fin, "%d ", &temp.cost);
			arr[cnt++] = temp;
		}
		fscanf(fin, "\n");
	}

	for (i = 0; i < n; ++i) {
		Parent[i] = i;
	}

	sort(arr, arr + cnt, cmp);

	int ret = 0;
	for (i = 0; i < cnt; ++i) {
		int xRoot = Find(arr[i].i);
		int yRoot = Find(arr[i].j);
		if (xRoot == yRoot)
			continue;
		ret += arr[i].cost;
		merge(xRoot, yRoot);
	}
	fprintf(fout, "%d\n", ret);
	return 0;
}
