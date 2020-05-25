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
int main() {
	file(); //TODO

	string x = "0101010101";				/// equals ??;	(dummy check)
	int n = 10; 		// num of bits
	for (int i = 0; i < (1 << n); ++i) {	// use bitmask to know if bit num j is on and loop each time num of digits
		string res = "0000000000";
		int j = 9, num = i;
		while (num) {
			res[j] = to_string(num % 2)[0];
			j--, num /= 2;
		}
		cout << res << "\n";
		if (res == x)
			cout << i;		// best result for dummy check
	}

	/////////////////////////////////////////////////////////////////////////

	int order[7] { 0, 1, 2, 3, 4, 5, 6 };
	do {
		for (auto it : order)
			cout << it << " ";
		cout << "\n";
	} while (next_permutation(order, order + 7));

	return 0;
}
