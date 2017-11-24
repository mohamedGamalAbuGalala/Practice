#include <bits/stdc++.h>

#define INF 1000000000
#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 20000 + 10;
const lli maxE = 1e5 + 10;

int toInt(const string &Text) {
	stringstream ss(Text);
	int result;
	return ss >> result ? result : 0;
}

int ar[10000], T, st, en, dig[4];

void digitize(int cur) {
	for (int i = 3; i >= 0; --i, cur /= 10)
		dig[i] = cur % 10;
}

int ddigit() {
	int ret = 0, cnt = 3;
	for (int i = 1; i <= 1000; i *= 10)
		ret += (dig[cnt--] * i);
	return ret;
}

void dijkstra() {
	int v[10000] = { 0 };
	priority_queue<ii> q;
	q.push(ii(0, st));
	while (q.size()) {
		int cur = q.top().second, cost = -q.top().first;
		q.pop();
		v[cur] = 1;
		if (cur == en) {
			cout << cost << "\n";
			return;
		}
		digitize(cur);
		for (int i = 0; i < 4; ++i) {
			int t = dig[i];
			for (int j = 0; j < 10; ++j) {
				dig[i] = j;
				int to = ddigit();
				if (!ar[to] && v[to] == 0 && to > 1000)
					q.push(ii(-1 - cost, to));
			}
			dig[i] = t;
		}
	}
	cout << "Impossible\n";
}

void seive() {
	for (int i = 2; i <= 100; ++i)
		if (!ar[i])
			for (int j = i * i; j < 10000; j += i)
				ar[j] = 1;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> T;
	seive();
	while (T--) {
		cin >> st >> en;
		dijkstra();
	}
}
