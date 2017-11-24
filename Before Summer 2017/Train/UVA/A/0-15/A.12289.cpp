#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	int n;
	string _1 = "one", _2 = "two", _3 = "three";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> tmp;
		int c1 = 0, c2 = 0, c3 = 0;
		for (int j = 0, si = tmp.size(); j < si; ++j) {
			// count ones
			if (j < 3 && tmp[j] == _1[j])
				c1++;
			// count Twos
			if (j < 3 && tmp[j] == _2[j])
				c2++;
			// count Threes
			if (j < 4 && tmp[j] == _3[j])
				c3++;
		}
		c1 = 3 - c1, c2 = 3 - c2, c3 = 4 - c3;
		if (c1 <= 1)
			cout << 1 << endl;
		else if (c2 <= 1)
			cout << 2 << endl;
		else if (c3 <= 1)
			cout << 3 << endl;
	}
	return 0;
}
