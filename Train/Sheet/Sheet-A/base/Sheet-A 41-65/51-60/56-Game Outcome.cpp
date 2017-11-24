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
	int n , ar [33][33],sum , i , j ,res = 0;
	cin>>n;
	for (i = 0; i < n; ++i) {
		sum = 0 ;
		for (j = 0; j < n; ++j) {
			cin>>ar[i][j];
			sum+=ar[i][j];
		}
		ar[i][n] = sum;
	}
	for (i = 0; i < n; ++i) {
		sum = 0;
		for (j = 0; j < n; ++j) {
			sum+=ar[j][i];
		}
		ar[n][i] = sum;
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if(ar[n][i]> ar[j][n])
				res++;
		}
	}
	cout<<res;
	return 0;
}
