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
		string s1, s2;
		cin >> s1 >> s2;
		int ss1 = s1.size(), ss2 = s2.size();
		if (ss1 != ss2) {
			cout << "No\n";
			continue;
		}
		bool exact = 1;
		for (int i = 0; i < ss1 && exact; ++i) {
			if (s1[i] != s2[i]) {
				if ((s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i'
						|| s1[i] == 'o' || s1[i] == 'u')
						&& (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i'
								|| s2[i] == 'o' || s2[i] == 'u'))
					continue;
				else {
					cout << "No\n";
					exact = 0;
				}
			}
		}
		if (exact)
			cout << "Yes\n";
	}
	return 0;
}
