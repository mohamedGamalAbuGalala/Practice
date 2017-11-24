#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
bool in(int &x) {
	return scanf("%d", &x);
}
void ot(int x) {
	printf("%d ", x);
}
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e5 + 5;
typedef long long int lli;
typedef vector<lli> vi;

int main() {
	file();
	pair<int, int[101]> ar[101];
	int n, m, f, t, res = 0, cnt, i, j, fl;
	queue<int> q;
	in(n), in(m);
	if (!m)
		return ot(0), 0;
	for (int i = 0; i < m; ++i)
		in(f), in(t), ar[f].second[t] = 1, ar[f].first++, ar[t].second[f] = 1, ar[t].first++;
	while (n--) {
		fl = 0;
		for (i = 0; i < 101; ++i)
			if (ar[i].first == 1)
				for (j = 0, cnt = 0, fl = 1; j < 101 and cnt < ar[i].first; ++j)
					if (ar[i].second[j] == 1)
						ar[i].second[j] = 0, ar[j].second[i] = 0, q.push(j), q.push(
								i);
		if (fl)
			res++;
		while (q.size())
			ar[q.front()].first--, q.pop();
	}
	ot(res);
	return 0;
}
