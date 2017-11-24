#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	string s;
	int T, t = 0;
	cin >> T;
	while (T--) {
		cin >> s;
		int ssi = s.size(), num = 0;
		char inp;
		cout << "Case " << ++t << ": ";
		for (int i = 0; i < ssi; ++i) {
			if (isalpha(s[i])) {
				for (int j = 0; j < num; ++j) {
					cout << inp;
				}
				inp = s[i];
				num = 0;
			} else {
				int d = s[i] - '0';
				num = (num * 10) + d;
			}
		}
		if (isalpha(s[ssi - 1]))
			cout << s[ssi - 1];
		else
			for (int i = 0; i < num; ++i) {
				cout << inp;
			}
		cout << "\n";
	}
	return 0;
}
