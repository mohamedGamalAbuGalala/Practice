#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;
int main() {
	string s, t;
	int res = 0;
	getline(cin, s);
	getline(cin, t);
	for (int i = 0, si = t.size(); i < si; ++i)
		if (t[i] == s[res])
			res++;
	cout << res + 1 << endl;
	return 0;
}
