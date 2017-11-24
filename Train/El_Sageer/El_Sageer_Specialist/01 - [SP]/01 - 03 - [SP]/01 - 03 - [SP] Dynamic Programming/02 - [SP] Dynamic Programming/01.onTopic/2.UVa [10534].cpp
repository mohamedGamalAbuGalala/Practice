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
#define in(n) scanf("%d",&n)	//scan int
#define ot(x) printf("%d", x)	//output int
#define forr(i,j, n) for(int i = j;i < n;i++)
#define frr(i,j, n) for(int i = j;i >= n;i--)

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

#define MAX_N 10000
int L[MAX_N], A[MAX_N], M[MAX_N], AA[MAX_N], f[MAX_N], b[MAX_N];

int main() { // dfil
	fl(); //TODO
	int n;
	while (in(n) != EOF) {
		forr(i, 0, n and in(A[i]))
			AA[n - i - 1] = A[i];
		int lis = 0, lws = -1, lds = 0;
		forr(i,0,n)
		{
			int pos = lower_bound(L, L + lis, A[i]) - L;
			L[pos] = A[i];
			if (pos + 1 > lis)
				lis = pos + 1;
			f[i] = lis;

			pos = lower_bound(M, M + lds, AA[i]) - M;
			M[pos] = AA[i];
			if (pos + 1 > lds)
				lds = pos + 1;
			b[n - i - 1] = lds;
		}

		forr(i,0,n)
			if (f[i] == b[i])
				lws = max(lws, f[i] + b[i] - 1);

		printf("%d\n", lws == -1 ? 1 : lws);
	}
	return 0;
}
