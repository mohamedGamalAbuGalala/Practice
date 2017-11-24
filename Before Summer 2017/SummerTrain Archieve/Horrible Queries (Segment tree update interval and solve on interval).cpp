///Horrible Queries (Segment tree update interval and solve on interval)

#include <iostream>

using namespace std;

int tree[250000], v[250000];

void update(int node, int s, int e, int x, int y, int val) {
	if (s > y || e < x) return;
	if (s >= x && e <= y) {
		v[node] += val;
		tree[node] += val * (e - s + 1);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, x, y, val);
	update(node * 2 + 1, mid + 1, e, x, y, val);

	tree[node] = tree[node * 2] + tree[node * 2 + 1] + (v[node] * (e - s + 1));
	return;
}

int solve(int node, int s, int e, int x, int y) {
	if (s > y || e < x) return 0;
	if (s >= x && e <= y) return tree[node];

	int elements = min(e, y) - max(s, x) + 1;
	int ret = 0, mid = (s + e) / 2;
	ret += solve(node * 2, s, mid, x, y);
	ret += solve(node * 2 + 1, mid + 1, e, x, y);
	return ret + (elements * v[node]);
}


int main() {
	return 0;
}
