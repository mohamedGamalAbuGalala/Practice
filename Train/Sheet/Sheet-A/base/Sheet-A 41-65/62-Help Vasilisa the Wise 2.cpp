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

int main() {
	int r1, r2, d1, d2, c1, c2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	for (int x = 1; x <= 9; ++x) {
		for (int y = 1; y <= 9; ++y) {
			if (x == y)
				continue;
			for (int z = 1; z <= 9; ++z) {
				if (z == x || z == y)
					continue;
				for (int w = 1; w <= 9; ++w) {
					if (z == w || x == w || y == w)
						continue;
					if ((r1 == (x + y)) && (r2 == (z + w)) && (d1 == (x + w))
							&& (d2 == (y + z)) && (c1 == (x + z))
							&& (c2 == (y + w))) {
						cout << x << " " << y << endl;
						cout << z << " " << w << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}
