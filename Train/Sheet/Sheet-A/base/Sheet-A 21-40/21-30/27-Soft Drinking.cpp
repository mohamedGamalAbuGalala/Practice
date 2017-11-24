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

using namespace std;
int main() {
	int n , k , l , c , d,p,nl,np,res,mlt,slicet,pt;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	mlt = (k*l)/nl;
	slicet=c*d;
	pt=p/np;
	res=min(mlt,min(slicet,pt)) / n;
	cout<<res<<endl;
	return 0;
}
