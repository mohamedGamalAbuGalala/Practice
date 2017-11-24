#include <bits/stdc++.h>
using namespace std;
void fl() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}

typedef vector<int> vi;
#define forr(i,j, n) for(int i = j;i < n;i++)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int T, n;
	vi a;
	cin >> T;
	while (T-- and cin >> n) {
		a.assign(n, 0);
		forr(i,1,100000)
		{
			bool don = 0;
			for (auto &aa : a) {
				int sq = sqrt(aa + i);
				if (sq * sq == (aa + i) or !aa) {
					aa = i, don = 1;
					break;
				}
			}
			if (!don) {
				cout << i - 1 << "\n";
				break;
			}
		}

	}
	return 0;
}

