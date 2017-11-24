#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;
int main() {
	int n ;
	bool res = 0;
	cin>>n;
	for (int i = 0; i < n && !res; ++i) {
		string name;
		int b , a;
		cin>>name>>b>>a;
		if(b>=2400)
			if(a>b)
				res=1;
	}
	if(res)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
