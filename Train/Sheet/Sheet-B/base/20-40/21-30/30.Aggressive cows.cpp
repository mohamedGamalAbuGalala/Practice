#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
//	freopen("alost.in", "r", stdin);
#endif
}
void in(int &x) {
	scanf("%d", &x);
}
void ot(int x) {
	printf("%d\n", x);
}
const int N = 1e5 + 5;

int st[N], n, c, T, s, e, m, ret;

bool ch(int g) {
	int pre = st[0], cnt = 1;
	for (int i = 0; i < n; ++i)
		if (st[i] >= pre + g)
			pre = st[i], cnt++;
	return cnt >= c;
}

int main() {
	file();
	in(T);
	while (T--) {
		in(n), in(c);
		for (int i = 0; i < n && cin >> st[i]; ++i)
			;
		sort(st, st + n);
		s = 0, e = 1e9;
		while (s <= e) {
			m = (s + e) / 2;
			if (ch(m))
				s = m + 1, ret = m;
			else
				e = m - 1;
		}
		ot(ret);
	}
	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
