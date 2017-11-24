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
	int s[4], res = 0, v[4];
	for (int i = 0; i < 4 && cin >> s[i]; ++i)
		;
	for (int i = 0; i < 4; ++i) {
		int cur = s[i];
		if (v[i] == 1)
			continue;
		for (int j = 0; j < 4; ++j) {
			if (i == j)
				continue;
			if (s[j] == cur)
				res++, v[j] = 1;
		}
	}
	cout << res << endl;
	return 0;
}
