#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	int T, t = 1, n;
	bool blank = 0;
	cin >> T;
	while (T--) {
		scanf("%d", &n);
		getchar();  // not working without
		if (blank)
			printf("\n");
		blank = 1;
		cout << "Case " << t++ << ":\n";
		for (int i = 0; i < n; ++i) {
			char inp[1000];
			gets(inp);
			bool space = 1;
			for (int j = 0; inp[j]; ++j) {
				if (inp[j] == ' ') {
					if (space)
						printf(" ");
					space = 0;
					continue;
				}
				cout << inp[j];
				space = 1;
			}
			printf("\n");
		}
	}
	return 0;
}
