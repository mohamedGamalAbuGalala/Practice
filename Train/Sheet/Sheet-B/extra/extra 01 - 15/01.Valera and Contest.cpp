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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, k, l, r, s, sk;
	cin >> n >> k >> l >> r >> s >> sk;
	int tsk = s - sk;
	for (int i = 0; i < k; cout << " ", i++)
		if (sk % k)
			cout << (sk / k) + 1, sk--;
		else
			cout << sk / k;
	for (int i = k; i < n; cout << " ", i++)
		if (tsk % (n - k))
			cout << (tsk / (n - k)) + 1, tsk--;
		else
			cout << tsk / (n - k);
	return 0;
}
