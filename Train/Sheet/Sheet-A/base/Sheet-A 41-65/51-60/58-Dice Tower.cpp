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
	int res = 2;
	int n, top, ar[4]={0};
	cin >> n >> top >> ar[0] >> ar[1];
	ar[2] = 7 - ar[0], ar[3] = 7 - ar[1];
	for (int i = 0; i < n - 1; ++i) {
		int l, r;
		if(res != 2){
			cin >> l >> r;
			continue;
		}
		res = 0;
		int le = 0 , ri = 0;
		cin >> l >> r;
		for (int j = 0; j < 4; ++j) {
			if (ar[j] == l)
				le = 1;
			if (ar[j] == r)
				ri = 1;
		}
		res = (le + ri);
	}
	if (res == 2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
