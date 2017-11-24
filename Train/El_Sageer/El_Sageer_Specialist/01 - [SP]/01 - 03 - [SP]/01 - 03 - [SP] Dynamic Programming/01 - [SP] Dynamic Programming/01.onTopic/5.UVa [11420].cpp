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
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

using lli = long long int;
lli dp[66][66][2];
int N, S;
lli slv(int idx = 0, int sec = 0, int L = 0) {
	if (idx == N) {
		if (sec == S)
			return 1;
		return 0;
	}
	lli &ret = dp[idx][sec][L];
	if (ret == -1) {
		ret = slv(idx + 1, sec + 1, 1);	// adding locked
		if (L)
			ret += slv(idx + 1, sec - 1, 0);		// adding unlocked on locked
		else
			ret += slv(idx + 1, sec, 0);		// adding unlocked on unlocked
	}
	return ret;
}

int main() { // dfil
	fl(); //TODO
	while (cin >> N >> S and N > -1 and S > -1) {
		mem(dp,-1), cout << slv() << "\n";
	}
	return 0;
}
