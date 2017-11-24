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

#define MAX_N 100000

int main() {
	file();
	vector<int> A;
	int t, x;
	scanf("%d\n\n", &t);
	while (t--) {
		A.clear();
		string s;
		while (getline(cin, s) && s != "") {
			stringstream ss(s);
			ss >> x;
			A.push_back(x);
		}

		int L[MAX_N], L_id[MAX_N], P[MAX_N];

		int lis = 0, lis_end = 0;
		for (int i = 0; i < sz(A); ++i) {
			int pos = lower_bound(L, L + lis, A[i]) - L;
			L[pos] = A[i];
			L_id[pos] = i;
			P[i] = pos ? L_id[pos - 1] : -1;
			if (pos + 1 > lis)
				lis = pos + 1, lis_end = i;
		}

		printf("Max hits: %d\n", lis);
		int x = lis_end;
		stack<int> ss;
		for (; P[x] >= 0; x = P[x])
			ss.push(A[x]);
		printf("%d\n", A[x]);
		for (; !ss.empty(); ss.pop())
			printf("%d\n", ss.top());
		if (t)
			printf("\n");
	}
	return 0;
}
