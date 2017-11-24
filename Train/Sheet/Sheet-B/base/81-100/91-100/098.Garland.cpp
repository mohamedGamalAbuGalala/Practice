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
#define sp() printf(" ")		//output single space
#define ln() printf("\n")		//output new line
#define in(n) scanf("%d",&n)	//scan int
#define inf(n) scanf("%lf",&n)	//scan double/float
#define otf(x) printf("%.2lf", x)// output double/float with 0.00

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int N;
double A;

double isValid(int N, double H1, double H2) {
	double H = 0;
	for (int i = 3; i <= N; i++) {
		H = 2 * H2 + 2 - H1;
		if (H < 0)
			return -1;
		H1 = H2, H2 = H;
	}
	return H;
}

double IBS() {
	double t, ans = 0.0, mid = 0.0, lo = 0.0, hi = A;
	for (int i = 0; i < 77; i++) {
		mid = (lo + hi) / 2.0;
		if ((t = isValid(N, A, mid)) >= 0)
			ans = t, hi = mid;
		else
			lo = mid;
	}
	return ans;
}

int main() { // dfil
	fl(); //TODO
	while (in(N) == 1 and inf(A))
		otf(IBS()), ln();
	return 0;
}
