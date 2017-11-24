#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define pb push_back
#define up upper_bound
#define lp lower_bound

using namespace std;
int main() {
	int res = 0 , k , r , cnt = 1;
	cin>>k>>r;
	res = k;
	while(1){
		if((res%10 == 0) || (res%10 == r))
			break;
		cnt++,res+=k;
	}
	cout<<cnt<<endl;
	return 0;
}
