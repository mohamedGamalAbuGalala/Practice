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

ll n,k;

ll calc (int m){
	ll res;
	if(k <= ((n/2)+m))
		res = k*2-1;
	else
		k -= ((n/2)+m),res=k*2;
	return res;
}

int main() {
	cin>>n>>k;
	if(n&1)
		cout<<calc(1);
	else
		cout<<calc(0);
	return 0;
}
