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
bool in(lli &x) {
//	return scanf("%lf", &x);		// double
//	return scanf("%d", &x);			// int
	return scanf("%lld", &x);			// long long int
}
void ot(int x) {
	printf("%d ", x);
//	printf("%lld ", x);		//  	long long int
//	printf("%.3lf ", x);
}
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size()))
#define cl(v,d) memset(v,d,sizeof(v))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e5 + 5;

int main() {
	file();
	string s1, s2;
	cin >> s1 >> s2;
	int i = 0, j = 0;
	if (sz(s1) != sz(s2)) {
		int j = 0;
		for (int i = 0; i < sz(s1); ++i)
			if (s1[i] == s2[j])
				j++;
		if (j == sz(s2))
			return cout << "automaton", 0;
	}
	int ar1[26] { 0 }, ar2[26] { 0 };
	for (int i = 0; i < sz(s1); ++i)
		ar1[s1[i] - 'a']++;
	for (int i = 0; i < sz(s2); ++i)
		ar2[s2[i] - 'a']++;

	for (int i = 0; i < 26; ++i) {
		if (sz(s1) < sz(s2) and ar1[i] and ar1[i] != ar2[i])
			return cout << "need tree", 0;
		else if (sz(s2) < sz(s1) and ar2[i] and ar1[i] < ar2[i])
			return cout << "need tree", 0;
		else if (sz(s1) == sz(s2) and ar1[i] != ar2[i])
			return cout << "need tree", 0;
	}
	if (sz(s1) == sz(s2))
		cout << "array";
	else
		cout << "both";
	return 0;
}
