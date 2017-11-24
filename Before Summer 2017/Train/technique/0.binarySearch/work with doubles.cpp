#include <bits/stdc++.h>

#define INF 1e18
#define EPS 1e-9
#define pb push_back
#define up upper_bound
#define lp lower_bound
#define fr(i, n)        for(int i=0;i<(int)(n);++i)
#define rep(i,n) fr( __typeof(n)i = 0 ; i < n ; i++)

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;

const lli maxN = 10000;
const lli maxE = 1e5 + 10;

bool check(double n) {
	return 0;
}

double binary(double start, double end) {
	fr(i, 100)
	{    // loop as much as u want
		double mid = (start + end) / 2;
		if (check(mid))
			end = mid;
		else
			start = mid;
	}

	if (check(end))
		return start;

	return -1;  // failed
}

double BS_double(double start, double end) {
	while (fabs(end - start) > EPS) { // iterate 100-500 iteration
		double mid = start + (end - start) / 2;
		if (check(mid))
			start = mid;
		else
			end = mid;
	}
	return start;
}

int main() {
	freopen("in.txt", "r", stdin);

	return 0;
}
