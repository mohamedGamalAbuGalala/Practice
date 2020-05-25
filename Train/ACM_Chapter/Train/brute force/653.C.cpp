#include <bits/stdc++.h>
using namespace std;

void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
//------------------------------------------------------------------------------Defines

//------------------------------------------------------------------------------

vector<int> points;
int n, arr[150002];
bool prob[150002] = { false };
bool check(int i) {
	if (i & 1)
		return ((i == 1 || arr[i] < arr[i - 1])
				&& (i == n || arr[i] < arr[i + 1]));
	return ((arr[i] > arr[i - 1]) && (i == n || arr[i] > arr[i + 1]));
}

int main() {
	file(); //TODO
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) {
		if (!check(i)) {
			points.push_back(i);
			prob[i] = true;
		}
	}
	if (points.size() > 6)    // Not worth considering (to avoid TLE)
		return printf("0"), 0;
	int res = 0;
	for (auto e : points)
		for (int j = 1; j <= n; j++) {
			if (!prob[j] || j > e) {
				swap(arr[e], arr[j]);
				bool b = check(j) && check(e);
				for (auto f : points)
					b &= check(f);
				if (b)
					res++;
				swap(arr[e], arr[j]);
			}
		}
	printf("%d", res);

	return 0;
}
