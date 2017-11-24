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
	int n , m , k , j , res;
	while(cin>>n>>m){
//		cout<<(n ^ m)<<endl;
		k = n & ~m;
		j = ~n & m;
		res = k | j;
		cout<<res<<endl;
	}
	return 0;
}
