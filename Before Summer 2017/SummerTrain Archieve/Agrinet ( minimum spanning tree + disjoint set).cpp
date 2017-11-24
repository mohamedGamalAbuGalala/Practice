///Agrinet ( minimum spanning tree + disjoint set)

#include <iostream>
#include <algorithm>
using namespace std;

class edge {
public:
	int x, y, cost;
};

bool cmp(edge a, edge b) {
	if (a.cost != b.cost) return a.cost < b.cost;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int n, grid[100][100], cnt = 0;
edge arr[10001];
int Parent[101], Rank[101];

int Find(int node) {
	if (Parent[node] == node) return node;
	return Parent[node] = Find(Parent[node]);
}

void Merge(int xRoot, int yRoot) {
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
	int i, j;

	cin >> n;
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		cin >> grid[i][j];

	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++) {
		edge temp;
		temp.x = i;
		temp.y = j;
		temp.cost = grid[i][j];
		arr[cnt++] = temp;
	}

	sort(arr, arr + cnt, cmp);

	for (i = 0; i<n; i++)
		Parent[i] = i;

	int ret = 0;
	for (i = 0; i<cnt; i++) {
		int xRoot = Find(arr[i].x);
		int yRoot = Find(arr[i].y);
		if (xRoot == yRoot) continue;

		ret += arr[i].cost;
		Merge(xRoot, yRoot);
	}

	cout << ret << endl;
	return 0;
}
