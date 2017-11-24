#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
bool in(int &x) {
//	return scanf("%lf", &x);		// double
	return scanf("%d", &x);			// int
//	return scanf("%lld", &x);			// long long int
}
void ot(int x) {
	printf("%d\n", x);
//	printf("%lld ", x);		//  	long long int
//	printf("%.3lf ", x);
}
void ln() {
	scanf("\n");
}
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define cl(v,d) memset(v,d,sizeof(v))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))

const int MN = 1e3 + 5;
const int MW = 1e3 + 5;

const int OO = 1e9;
typedef pair<lli, string> lls;

int main() {
	file();
	int n, A[101][101];
	in(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n and in(A[i][j]); ++j) {
			if (i)
				A[i][j] += A[i - 1][j];
			if (j)
				A[i][j] += A[i][j - 1];
			if (i and j)
				A[i][j] -= A[i - 1][j - 1];
		}

	int maxSubRect = -127 * 100 * 100;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = i; k < n; k++)
				for (int l = j; l < n; l++) {
					int subRect = A[k][l];
					if (i)
						subRect -= A[i - 1][l];
					if (j)
						subRect -= A[k][j - 1];
					if (i and j)
						subRect += A[i - 1][j - 1];
					maxSubRect = max(maxSubRect, subRect);
				}
	ot(maxSubRect);
	return 0;
}
