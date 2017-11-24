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
	double ar[10][4], x, y;
	int n = 0, n2 = 0;
	char c;
	bool contained;
	while (1) {
		cin >> c;
		if (c == '*')
			break;
		if (c == 'r') {
			cin >> ar[n][0] >> ar[n][1] >> ar[n][2] >> ar[n][3];
			n++;
		}
	}
	while (1) {
		cin >> x >> y;
		if (x == 9999.9 && y == 9999.9)
			break;
		n2++, contained = 0;
		for (int i = 0; i < n; ++i) {
			if (x > ar[i][0] && x < ar[i][2] && y > ar[i][3] && y < ar[i][1]) {
				cout << "Point " << n2 << " is contained in figure " << i + 1
						<< endl;
				contained = 1;
			}
		}
		if (!contained)
			cout << "Point " << n2 << " is not contained in any figure" << endl;
	}
	return 0;
}
