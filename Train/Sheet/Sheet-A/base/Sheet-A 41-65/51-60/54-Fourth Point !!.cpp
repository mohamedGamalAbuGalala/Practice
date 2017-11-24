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
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double x, y;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
		if (x1 == x3 && y1 == y3) {
			x = x2 + x4 - x3;
			y = y2 + y4 - y3;
		} else if (x1 == x4 && y1 == y4) {
			x = x2 + x3 - x4;
			y = y2 + y3 - y4;
		} else if (x2 == x3 && y2 == y3) {
			x = x1 + x4 - x3;
			y = y1 + y4 - y3;
		} else {
			x = x1 + x3 - x4;
			y = y1 + y3 - y4;
		}

		printf("%.3f %.3f\n", x, y);
	}
	return 0;
}
