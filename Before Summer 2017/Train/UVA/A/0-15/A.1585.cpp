#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d\n", &T);
	while (T--) {
		int res = 0, cur = 0;
		string inp;
		getline(cin, inp);
		int inpsi = inp.size();
		for (int i = 0; i < inpsi; ++i) {
			if (inp[i] == 'O')
				cur++, res += cur;
			else {
				cur = 0;
				continue;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
