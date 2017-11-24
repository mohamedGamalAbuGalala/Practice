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
	int tx[3001] { 0 }, tz[3001] { 0 }, p, q, l, r, a, b, res = 0;
	in(p), in(q), in(l), in(r);
	for (int i = 0; i < p; ++i) {
		in(a), in(b);
		for (int k = a; k <= b; ++k)
			tz[k] = 1;
	}
	for (int i = 0; i < q; ++i) {
		in(a), in(b);
		for (int k = a; k <= b; ++k)
			tx[k] = 1;
	}
	for (int i = l; i <= r; ++i) {
		if (i)
			for (int k = 1000; k >= 0; --k)
				if (tx[k])
					tx[k + i] = 1, tx[k] = 0;
		for (int k = 0; k < 1001; ++k)
			if (tx[k] and tz[k]) {
				res++;
				break;
			}
		if (i)
			for (int k = 0; k < 1001; ++k)
				if (tx[k])
					tx[k - i] = 1, tx[k] = 0;
	}
	ot(res);
	return 0;
}
