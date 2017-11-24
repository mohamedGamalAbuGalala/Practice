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
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))	// eg... vector<int> v; sz(v)
#define mem(a,b) memset(a,b,sizeof(a))

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit , def*

int sgn[66];
int a[66], n;
bool dp[66][66][6123];
set<int> se;

void slv(int i = 0, int op = 0, int sm = 0) {
	int idsm = sm;
	if (idsm + 3000 < 6001)
		idsm += 3000;
	bool &ret = dp[i][op][idsm];
	if (i == n) {
		se.insert(idsm);
		return;
	}
	if (!ret) {
		ret = 1;
		int nsm = sm + a[i] * sgn[i] * ((op & 1) ? -1 : 1);
		if (sgn[i] == -1)
			slv(i + 1, op + 1, nsm);
		if (op)
			slv(i + 1, op - 1, nsm);
		slv(i + 1, op, nsm);
	}
}

int main() { // dfil
	fl(); //TODO
	string x;
	while (getline(cin, x) and x != "") {
		stringstream ss(x);
		ss >> a[0], mem(dp, 0), se.clear(), sgn[0] = 1;
		char sig;
		int ii = 1, jj = 1;
		while (ss >> sig >> a[ii++])
			sgn[jj++] = sig == '-' ? -1 : 1;
		n = ii - 1, slv();
		printf("%d\n",sz(se));
	}
	return 0;
}
