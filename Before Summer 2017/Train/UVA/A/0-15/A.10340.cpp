#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	string S,T;
	while (cin>>S>>T) {
		int i, j = 0;
		for (i = 0; S[i]; i++) {
			for (; T[j]; j++)
				if (S[i] == T[j]) {
					break;
				}
			if (T[j] == '\0')
				break;
			j++;
		}
		if (S[i] == '\0')
			puts("Yes");
		else
			puts("No");
	}

	/*
	 string s, t;
	 while (cin >> s >> t) {
	 int ssi = s.size(), tsi = t.size(), cnt = 0;
	 bool ns = 0;
	 for (int i = 0; i < tsi; ++i) {
	 if (s[cnt] == t[i]) {
	 cnt++;
	 continue;
	 } else
	 ns = 1;
	 }
	 if (ns && cnt == ssi)
	 cout << "Yes\n";
	 else
	 cout << "No\n";
	 }
	 */

	return 0;
}
