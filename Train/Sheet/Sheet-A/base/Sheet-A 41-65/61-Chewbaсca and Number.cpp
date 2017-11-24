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
	string n;
	cin>>n;
	for (int i = 0 , si = n.size(); i < si; ++i) {
		if(i == 0 && n[0] == '9')
			continue;
		int d = n[i] - '0' , rev = 9-d;
		d= (rev < d)? rev : d;
		n[i] = d + '0';
	}
	cout<<n;
	return 0;
}
