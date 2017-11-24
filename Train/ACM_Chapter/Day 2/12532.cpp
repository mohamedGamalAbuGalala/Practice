#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
const int N = 100000 + 5;
ll arr[N];
ll tree[4 * N];

ll merge(ll x, ll y) {
	return x * y;
}

void build(int ind, int st, int en) {

	if (st == en) {
		if (arr[st] < 0)
			tree[ind] = -1;
		else if (arr[st] > 0)
			tree[ind] = 1;
		else
			tree[ind] = 0;

		return;
	}

	int mid = (st + en) / 2;
	int right = 2 * ind + 1;
	int left = 2 * ind;

	build(left, st, mid);
	build(right, mid + 1, en);

	tree[ind] = merge(tree[right], tree[left]);
}

ll query(int ind, int st, int en, int i, int j) {
	if (j < st || en < i)			// no intersect
		return 1;

	if (i <= st && en <= j)  		// begin & end in [i ... j]
		return tree[ind];

	int mid = (st + en) / 2;
	int left = 2 * ind;
	int right = 2 * ind + 1;

	ll q1 = query(left, st, mid, i, j);
	ll q2 = query(right, mid + 1, en, i, j);

	return merge(q1, q2);
}
void update(int pos, int st, int en, int idx, ll val) {
	if (idx < st || idx > en)
		return;

	if (st == en && idx == en) {
		if (val < 0)
			tree[pos] = -1;
		else if (val > 0)
			tree[pos] = 1;
		else
			tree[pos] = 0;

		arr[idx] = val;
		return;
	}
	int mid = (st + en) / 2;
	int left = 2 * pos;
	int right = 2 * pos + 1;

	update(left, st, mid, idx, val);
	update(right, mid + 1, en, idx, val);

	tree[pos] = merge(tree[right], tree[left]);
}
int n, k;
int main() {
	file();
	while (cin >> n >> k) {
		for (int i = 0; i < 4 * N; i++)
			tree[i] = 1;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		build(1, 1, n);
		char c;
		for (int i = 0; i < k; i++) {
			cin >> c;
			if (c == 'C') {
				int idx;
				ll val;
				cin >> idx >> val;
				update(1, 1, n, idx, val);
			} else {
				int st, en;
				cin >> st >> en;
				ll res = query(1, 1, n, st, en);
				if (res > 0)
					cout << "+";
				else if (res < 0)
					cout << "-";
				else
					cout << "0";

			}
		}

		cout << endl;
	}

	return 0;
}
