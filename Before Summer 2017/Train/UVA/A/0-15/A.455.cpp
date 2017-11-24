#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string inp;
		cin >> inp;
		bool got = 1;
		int si = inp.size(), i;
		for (i = 1; i < si; ++i) {
			if (si % i != 0)
				continue;
			for (int j = i; j < si; j++)
				if (inp[j] != inp[j % i]) {
					got = 0;
					break;
				}
			if (got)
				break;
			got  = 1;
		}
		cout << i << "\n";
		if (T)
			printf("\n");
	}
	return 0;
}
