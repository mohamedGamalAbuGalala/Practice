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

bool ss;
int cnt, mss, ps1;

void slv(int x, int ind, string s, int ms) {
	if (ind == (int) s.size()) {
		if (ss)
			ps1 = x;
		else if (x == ps1)
			cnt++;
		mss = ms;
		return;
	}
	if (s[ind] == '+')
		slv(x + 1, ind + 1, s, ms);
	else if (s[ind] == '-')
		slv(x - 1, ind + 1, s, ms);
	else
		slv(x + 1, ind + 1, s, ms + 1), slv(x - 1, ind + 1, s, ms + 1);
}

int main() {
	file();
	string s1, s2;
	cin >> s1 >> s2;
	ss = 1, slv(0, 0, s1, 0);
	ss = 0, slv(0, 0, s2, 0);
	int p = pow(2, mss);
	double res = (double) cnt / (double) p;
	printf("%.13lf", res);
	return 0;
}
