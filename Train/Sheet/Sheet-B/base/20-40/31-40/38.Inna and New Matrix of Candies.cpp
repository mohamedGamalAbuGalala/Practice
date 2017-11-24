#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
bool in(int &x) {
//	return scanf("%lf", &x);		// double
	return scanf("%d", &x);			// int
//	return scanf("%lld", &x);			// long long int
}
void ot(int x) {
	printf("%d ", x);
}
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e3 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
int main() {
	file();
	int n, m;
	string x;
	set<int> s;
	in(n), in(m);
	for (int i = 0; i < n; ++i) {
		ii p { -1, -1 };
		cin >> x;
		for (int j = 0; j < m and (p.first == -1 or p.second == -1); ++j) {
			if (x[j] == 'G')
				p.first = j;
			else if (x[j] == 'S')
				p.second = j;
		}
		if (p.first >= p.second)
			return ot(-1), 0;
		s.insert((p.second - p.first));
	}
	ot((int) s.size());
	return 0;
}
