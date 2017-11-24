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

using namespace std;

int main() {
	char d;
	string kb = "qwertyuiop[asdfghjkl;zxcvbnm,./";
	string inp;
	cin>>d;
	cin>>inp;
	for (int i = 0 , s =inp.size(); i < s; ++i) {
		int ind = kb.find(inp[i]);
		if(d == 'R')
			cout<<kb[ind-1];
		else if(d == 'L')
			cout<<kb[ind+1];
	}
	return 0;
}
