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

////////////////////////////////////////////////////////////////////////////////////////////////
// snippet  ::  dinp , dhelp , dvec , lli , dfor , dcons , dbit

int main() { // dfil
	fl(); //TODO
	int n, i = 0, j = 0;
	;
	char s[1005];
	cin >> n >> s;
	while (s[i] == '.')
		i++;
	while (n > 0 and s[n - 1] == '.')
		s[n--] = 'L';
	while (s[j] != 'L')
		j++;
	cout << i + 1 << " " << j;
	return 0;
}
