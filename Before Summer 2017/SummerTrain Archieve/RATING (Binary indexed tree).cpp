///RATING (Binary indexed tree)


class node {
public:
	int x, y;
};

bool cmp(node a, node b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int n;
node arr[300000];
int tree[100000];

void update(int ind, int val) {
	for (int i = ind; i <= 100000; i += (i&(-i)))
		tree[i] += val;
	return;
}

int solve(int ind) {
	int i, ret = 0;
	for (i = ind; i>0; i -= (i&(-i)))
		ret += tree[i];
	return ret;
}

int main() {
	cin >> n;
	for (i = 0; i<n; i++)
		cin >> arr[i].x >> arr[i].y;

	sort(arr, arr + n, cmp);

	for (i = 0; i<n; i++) {
		ret += solve(arr[i].y);
		update(arr[i].y, 1);
	}
}
