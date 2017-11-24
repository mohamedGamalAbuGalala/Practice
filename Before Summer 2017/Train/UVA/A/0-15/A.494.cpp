#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	string inp;
	while (getline(cin, inp)) {
		int res = 0;
		for (int i = 0, si = inp.size(); i < si; ++i) {
			if (isalpha(inp[i])) {
				res++;
				while (isalpha(inp[i]))
					i++;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
