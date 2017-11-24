#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
ll arr[N + 2];
ll tree[2 * N];
ll lazy[2 * N];
struct SegmentTree {

	SegmentTree() {

	}
	void build(int cur, int l, int r) {
		lazy[cur] = 0;
		if (l == r) {
			tree[cur] = arr[l];
			return;
		}
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;
		build(left, l, mid);
		build(right, mid + 1, r);
		tree[cur] = min(tree[left], tree[right]);
	}

	void update(int cur, int l, int r, int ind, ll val) {
		if (ind < l || ind > r)
			return;
		if (l == r && ind == l) {
			tree[cur] += val;
			return;
		}
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;
		update(left, l, mid, ind, val);
		update(right, mid + 1, r, ind, val);
		tree[cur] = min(tree[left], tree[right]);
	}

	void propagte(int cur, int l, int r, int left, int right) {
		if (lazy[cur] != 0) {
			tree[cur] += lazy[cur];
			if (l != r){
				lazy[left] += lazy[cur];
				lazy[right] += lazy[cur];
			}
			lazy[cur] = 0;
		}
	}

	void updateRange(int cur, int l, int r, int x, int y, ll val) {
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;

		propagte(cur, l, r, left, right);

		if (l > y || x > r)
			return;

		if (l >= x && r <= y) {
			lazy[cur] += val;
			propagte(cur, l, r, left, right);
			return;
		}

		updateRange(left, l, mid, x, y, val);
		updateRange(right, mid + 1, r, x, y, val);
		tree[cur] = min(tree[left], tree[right]);
	}

	ll getAnswer(int cur, int l, int r, int x, int y) {
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;

		propagte(cur, l, r, left, right);

		if (y < l || x > r)
			return OO;
		if (l >= x && r <= y)
			return tree[cur];

		ll res1 = getAnswer(left, l, mid, x, y);
		ll res2 = getAnswer(right, mid + 1, r, x, y);
		return min(res1, res2);
	}
};

SegmentTree x;
int n, m, a, b, c;
char buf[10000000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= N; i++)
		arr[i] = OO;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		arr[i] = (ll) a;
	}
	x.build(1, 1, N);
	scanf("%d", &m);
	gets(buf);
	for (int i = 0; i < m; i++) {
		gets(buf);
		stringstream ss(buf);
		ss >> a >> b;
		a++;
		b++;
		if (ss >> c) {
			if (c) {
				if (a > b) {
					x.updateRange(1, 1, N, 1, b, c);
					x.updateRange(1, 1, N, a, n, c);
				} else
					x.updateRange(1, 1, N, a, b, c);
			}
		} else {
			if (a > b)
				cout
						<< min(x.getAnswer(1, 1, N, 1, b),
								x.getAnswer(1, 1, N, a, n)) << "\n";
			else
				cout << x.getAnswer(1, 1, N, a, b) << "\n";
		}
	}
	return 0;
}