#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main() {
	int T, t = 0, n;
	cin >> T;
	while (T--) {
		char c;
		cin >> c >> c >> n;
		ll ar[n + 1][n + 1];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n && cin >> ar[i][j]; ++j)
				;
		bool sym = 1;
		int u = 1, v = n;     // u = up ..... v = down
		while (u <= v && sym) {
			int i = 1, j = n;
			while (i <= n && sym) {
				if (ar[u][i] != ar[v][j])
					sym = 0;
				if (ar[u][i] < 0 || ar[v][j] < 0)
					sym = 0;
				i++;
				j--;
			}
			u++;
			v--;
		}
		printf("Test #%d: ", ++t);
		if (sym)
			printf("Symmetric.");
		else
			printf("Non-symmetric.");
		printf("\n");
	}
	return 0;
}
