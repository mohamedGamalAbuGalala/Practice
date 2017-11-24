#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

struct Pt {
	int x, y;
};
Pt D[200000];

int main() {
	int n, i;
	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &D[i].x, &D[i].y);
		int mx, my;
		int stan = 0, olli = 0;
		mx = D[n / 2].x, my = D[n / 2].y;
		for (i = 0; i < n; i++) {
			if (D[i].x > mx) {
				if (D[i].y > my)
					stan++;
				if (D[i].y < my)
					olli++;
			}
			if (D[i].x < mx) {
				if (D[i].y > my)
					olli++;
				if (D[i].y < my)
					stan++;
			}
		}
		printf("%d %d\n", stan, olli);
	}
	return 0;
}
