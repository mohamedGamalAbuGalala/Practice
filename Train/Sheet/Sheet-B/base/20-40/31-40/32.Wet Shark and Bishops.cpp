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
const int N = 1e5 + 5;
typedef long long int lli;
typedef vector<lli> vi;
int main() {
	file();
	map<int, int> sm, sb;
	map<int, int>::iterator it;
	int ret = 0, x, y, n;
	in(n);
	for (int i = 0; i < n and in(x) and in(y); ++i)
		sm[x + y]++, sb[x - y]++;
	for (it = sm.begin(); it != sm.end(); it++) {
		int cur = it->second;
		ret += (cur * (cur - 1)) / 2;
	}
	for (it = sb.begin(); it != sb.end(); it++) {
		int cur = it->second;
		ret += (cur * (cur - 1)) / 2;
	}
	ot(ret);
	return 0;
}
/*




















 scanf("%[^\n]%c",n);
 */
