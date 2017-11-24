///The great ball(Segment tree Update an interval and query on one index + RankingCompression)



int tree[250000];
int n;
int arr[100000][2];
set<int> S;
map<int, int> rank;

void update(int node, int s, int e, int x, int y) {
	if (s > y || e < x) return;
	if (s >= x && e <= y) {
		tree[node]++;
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, x, y);
	update(node * 2 + 1, mid + 1, e, x, y);
	return;
}

int solve(int node, int s, int e, int ind) {
	if (ind > e || ind < s) return 0;
	if (s == e) {
		if (s == ind) return tree[node];
		return 0;
	}

	int ret = tree[node], mid = (s + e) / 2;
	ret += solve(node * 2, s, mid, ind);
	ret += solve(node * 2 + 1, mid + 1, e, ind);
	return ret;
}

int main() {
	int i, ret = 0;

	cin >> n;
	for (i = 0; i<n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		S.insert(arr[i][0]);
		S.insert(arr[i][1]);
	}
	int cur, cnt = 0;
	while (S.size()) {
		cur = *S.begin();
		S.erase(S.begin());
		rank[cur] = cnt++;
	}
	for (i = 0; i<n; i++) {
		arr[i][0] = rank[arr[i][0]];
		arr[i][1] = rank[arr[i][1]];
	}
	//done with ranking.

	for (i = 0; i<n; i++)
		update(1, 0, cnt - 1, arr[i][0], arr[i][1]);

	for (i = 0; i<cnt; i++)
		ret = max(ret, solve(1, 0, cnt - 1, i));
}