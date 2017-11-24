#include <bits/stdc++.h>

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;
/*
 *
1 1 1
1 1 1 1
2 2 2
1 1 1 2
1 1 2 1
493 182 3
349 148 363 146
241 123 443 147
303 124 293 17
15 10 3
3 3 7 1
7 8 3 6
7 11 3 13
0 0 0
*/
int main() {
	int w, h, n;
//	bool v[501][501];
	while (scanf("%d %d %d", &w, &h, &n)) {

		if (w == 0 && h == 0 && n == 0)
			break;

		//		memset(v, 0, sizeof v);

//		bool v[w + 1][h + 1];

		bool v[505][505];
//		memset(v, 0, sizeof v);

		for (int i = 0; i < 505; i++)
			memset(v[i], 0, sizeof(v[i]));

		for (int k = 1; k <= n; k++) {
			int x1, y1, x2, y2;

			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

//			int a = min(x1, x2);
//			int c = max(x1, x2);
//
//			int b = min(y1, y2);
//			int d = max(y1, y2);

			if (x1 > x2 && y1 <= y2)
				swap(x1, x2);

			else if (x1 >= x2 && y1 >= y2) {
				swap(x1, x2);
				swap(y1, y2);
			}

			else if (x1 <= x2 && y1 > y2)
				swap(y1, y2);

//			for (int i = a; i <= c; i++)
//				for (int j = b; j <= d; j++)
//					v[i][j] = 1;

			for (int i = x1; i <= x2; i++)
				for (int j = y1; j <= y2; j++)
					v[i][j] = 1;
		}
		int res = 0;
		for (int i = 1; i <= w; i++)
			for (int j = 1; j <= h; j++)
				if (v[i][j] == 0)
					res++;

		if (res == 0)
			puts("There is no empty spots.");
		else if (res == 1)
			puts("There is one empty spot.");
		else
			printf("There are %d empty spots.\n", res);
	}
	return 0;
}
