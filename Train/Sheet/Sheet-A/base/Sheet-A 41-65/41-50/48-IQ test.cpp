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
	int n ,cnt =0 ,lo , le , inp;
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin>>inp;
		if(inp & 1)
			cnt++,lo = i+1;
		else
			le = i+1;
	}
	if(cnt > 1)
		cout<<le;
	else
		cout<<lo;
	return 0;
}
