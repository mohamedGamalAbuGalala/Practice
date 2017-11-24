#include <bits/stdc++.h>
using namespace std;
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
	printf("%d ", x);
//	printf("%lld ", x);		//  	long long int
//	printf("%.3lf ", x);
}
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e3 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;

bool cmp(pair<double, int> b, pair<double, int> a) {
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}

int main() {
	file();
	int n, t1, t2, k, a, b, cnt = 0;
	vector<pair<double, int>> ar;
	in(n), in(t1), in(t2), in(k);
	double per = (double) (100 - k) / 100.0;
	for (int i = 0; i < n; ++i) {
		in(a), in(b);
		ar.pb( { max((a * t1 * per) + (b * t2), (a * t2) + (b * t1 * per)),
				++cnt });
	}
	sort(ar.begin(), ar.end(), cmp);
	for (int i = 0; i < (int) ar.size(); ++i)
		printf("%d %.2lf\n", ar[i].second, ar[i].first);
	return 0;
}
