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
	getchar();
	while (T--) {
		string inp;
		getline(cin, inp);
		int f[26] = { 0 }, si = inp.size(), mx = -1;
		for (int i = 0; i < si; ++i) {
			if (!isalpha(inp[i]))
				continue;
			f[(tolower(inp[i]) - 97)]++;
		}
		for (int i = 0; i < 26; ++i)
			mx = max(mx, f[i]);
		for (int i = 0; i < 26; ++i)
			if (f[i] == mx)
				printf("%c", (i + 97));
		cout << "\n";
	}
	return 0;
}
