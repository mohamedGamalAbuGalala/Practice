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

int dj[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, di[] = { -1, 0, 1, -1, 0, 1, -1, 0,
		-1 }, n, img;
char ar[26][26];

void flood(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		return;
	if (ar[i][j] == '0')
		return;
	ar[i][j] = '0';
//	for (int k = 0; k < 9; ++k)
//		flood(i + di[k], j + dj[k]);
	for (int k = -1; k < 2; ++k)
		for (int l = -1; l < 2; ++l)
			flood(i + k, j + l);
}

int main() {
	while (cin >> n) {
		int res = 0;
		for (int i = 0; i < n && cin >> ar[i]; ++i)
			;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (ar[i][j] == '1')
					res++, flood(i, j);
		cout << "Image number " << ++img << " contains " << res
				<< " war eagles." << endl;
	}
	return 0;
}
