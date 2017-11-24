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

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;
int main() {
	unsigned long int n;
	while (cin >> n && n != 0) {
		unsigned long int x = sqrt(n);
		cout << ((x*x==n) ? "yes" : "no") << endl;
	}
	return 0;
}
